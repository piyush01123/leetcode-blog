const axios = require('axios');
const fs = require('fs');
const { Octokit } = require('@octokit/rest');
const core = require('@actions/core');
const { context } = require('@actions/github');
const glob = require("glob");

const maxRetries = 8; // Number of times to do GET on LC api
const commit_message = 'Sync LeetCode posts';
const blog_branch = "lcblog"
const owner = context.repo.owner;
const repo = context.repo.repo;
const leetcodeCSRFToken = process.env.LEETCODE_CSRF_TOKEN;
const leetcodeSession = process.env.LEETCODE_SESSION;
const githubToken = process.env.GITHUB_TOKEN;
const octokit = new Octokit({
	auth: githubToken,
	userAgent: 'LeetCode sync to GitHub - GitHub Action',
});
const URL = 'https://leetcode.com/graphql/';
const leetcodeId = process.env.LEETCODE_ID;;
const config = {
	headers: {
		'X-CSRFToken': leetcodeCSRFToken,
		'Cookie': `csrftoken=${leetcodeCSRFToken}; LEETCODE_SESSION=${leetcodeSession};`,
		'Content-Type': 'application/json'
	},
	method: 'post',
	maxBodyLength: Infinity,
};


async function getLastTimestamp()
{
	let branches = await octokit.repos.listBranches({
		owner: owner,
		repo: repo
	});
	let branchNames = [];
	for (let branch of branches.data) branchNames.push(branch.name);
	if (!branchNames.includes(blog_branch)) return 0;
	let commits = await octokit.repos.listCommits({
		owner: owner,
		repo: repo,
		per_page: 100,
		sha: blog_branch
	});
	let lastTimestamp = 0;
	for (let commit of commits.data) {
	  if (!commit.commit.message.startsWith(commit_message)) continue;
	  lastTimestamp = Date.parse(commit.commit.committer.date) / 1000;
	}
	return lastTimestamp;
}


async function initBranch()
{
	let mytree = [];
	let paths = glob.sync("template/**/*.*");
	paths.push("template/Gemfile");
	paths.push("template/_posts/gitinclude");
	paths.push("template/_tag/gitinclude");
	for (let path of paths)
	{
		let content = fs.readFileSync(path, {encoding:'utf8', flag:'r'});
		let node = {
			"path": path.replace("template/",''),
			"mode": "100644",
			"content": content,
		}
		if (path.endsWith("_config.yml")) node.content = node.content.replace("REPLACE_BASEURL",repo).replace("REPLACE_USERNAME",owner)
		console.log(node.path);
		mytree.push(node);
	}
	// fs.writeFileSync("test.json", JSON.stringify(mytree));
	let treeResponse = await octokit.git.createTree({
		owner: owner,
		repo: repo,
		sha: blog_branch,
		tree: mytree
	});
	let commitResponse = await octokit.git.createCommit({
		owner: owner,
		repo: repo,
		message: `Init Branch - ${new Date().toUTCString()}`,
		tree: treeResponse.data.sha,
	});
	await octokit.git.createRef({
		owner: owner,
		repo: repo,
		sha: commitResponse.data.sha,
		ref: 'refs/heads/' + blog_branch,
		force: true
	});
	await octokit.git.updateRef({
		owner: owner,
		repo: repo,
		sha: commitResponse.data.sha,
		ref: 'heads/' + blog_branch,
		force: true
	});
}


async function getAllQuestions(update=false){
	let url = `https://raw.githubusercontent.com/${owner}/${repo}/${blog_branch}/question_data.json`;
	let question_data = []
	try{
		let r = await axios.get(url);
		question_data = (r.data);
	} catch(err) {
		console.log("URL not found. Starting from beginning...");
	}
	// console.log(question_data[1000], "QD1000")
	if (!update) return question_data;
	let question_slugs = [];
	for (let question_datum of question_data) question_slugs.push(question_datum.titleSlug)
	for (let skip of [0,1000,2000,3000,4000,5000])
	{
		let curr_config = config;
		curr_config.data = JSON.stringify({
			"query": "    query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {  problemsetQuestionList: questionList(    categorySlug: $categorySlug    limit: $limit    skip: $skip    filters: $filters  ) {    total: totalNum    questions: data {      acRate      difficulty      freqBar      frontendQuestionId: questionFrontendId      isFavor      paidOnly: isPaidOnly      status      title      titleSlug      topicTags {        name        id        slug      }      hasSolution      hasVideoSolution    }  }}    ",
			"variables": {
				"categorySlug": "",
				"filters": {},
				"limit": 1000,
				"skip": skip,
			}
		});
		let response = await axios(URL, curr_config);
		for (let question_datum of response.data.data.problemsetQuestionList.questions)
		{
			if (question_slugs.includes(question_datum.titleSlug)) continue;
			let curr_config = config;
			curr_config.data = JSON.stringify({
				"query": "    query questionContent($titleSlug: String!) {  question(titleSlug: $titleSlug) {    content     }}    ",
				"variables": {
					"titleSlug": question_datum.titleSlug,
					"username": leetcodeId
				}
			});
			let response = await axios(URL,curr_config);
			// console.log(JSON.stringify(response.data));
			question_datum.content = response.data.data.question.content;;
			question_data.push(question_datum);
			console.log("Saving question", question_datum.frontendQuestionId, question_datum.title);
		}
	}
	// fs.writeFileSync(`lc_${Date.now()}_question_data.json`, JSON.stringify(question_data));
	// for (let question_datum of question_data) if (question_datum.content) 
	// 	fs.writeFileSync(`question_contents/question_${question_datum.frontendQuestionId}_${question_datum.titleSlug}.md`, question_datum.content);
	return question_data;
}


async function getAllPosts(lastTimestamp)
{
	let post_data = [];
	let curr_config = config;
	curr_config.data = JSON.stringify({
		"query": "query userSolutionTopics($username: String!, $orderBy: TopicSortingOption, $first: Int) {userSolutionTopics( username: $username orderBy: $orderBy first: $first){pageInfo {hasNextPage}edges {node{ id title url questionTitle post {creationDate}}}}}",
		"variables": {
			"first": 3000,
			"orderBy": "newest_to_oldest",
			"username": leetcodeId
		}
	});
	let response = await axios(URL,curr_config);
	for (let node of response.data.data.userSolutionTopics.edges)
	{
		let post = node.node;
		let curr_config = config;
		curr_config.data = JSON.stringify({
			"query": "query communitySolution($topicId: Int!){topic(id: $topicId) {id title solutionTags {name} post {id content creationDate}}}",
			"variables": {
				"topicId": parseInt(post.id)
			}
		});
		let response = await axios(URL,config);
		response.data.data.topic.post.content = response.data.data.topic.post.content.replace(/\\n/g, '\n').replace(/\\"/g, '"').replace(/\\'/g, "'").replace(/\\\\/g, '\\').replace(/\\t/g, '\t');
		post.post_data = response.data.data.topic;
		console.log("Time of posting:", Date(post.post_data.post.creationDate));
		if (post.post_data.post.creationDate < lastTimestamp) break;
		post_data.push(post);
		console.log("Done post", post.id, post.title, '-', post.questionTitle);
	}
	// fs.writeFile(`./jsons/lc_${Date.now()}_post_data.json`, JSON.stringify(post_data), err=>{});
	// for (let post_datum of post_data)
	// fs.writeFileSync(`post_contents/post_${post_datum.id}_${post_datum.title.replace(/\//g,' or ')}_${post_datum.questionTitle}.md`, post_datum.post_data.post.content);
	return post_data;
}


async function sync()
{
	console.log("leetcodeCSRFToken", leetcodeCSRFToken);
	console.log("leetcodeSession", leetcodeSession);
	console.log("githubToken", githubToken);

	let branches = await octokit.repos.listBranches({
		owner: owner,
		repo: repo
	});
	let branchNames = [];
	for (let branch of branches.data) branchNames.push(branch.name);
	if (!branchNames.includes(blog_branch)) await initBranch();

	let lastTimestamp = await getLastTimestamp();
	console.log("Last commit time with sync msg", Date(lastTimestamp))
	let question_data = await getAllQuestions();
	let post_data = await getAllPosts(lastTimestamp);
	let merged_data = [];
	let treeData = [];
	let updated = false;
	for (let i=0; i<post_data.length; i++)
	{
		let qdata = null;
		let qtitle = post_data[i].questionTitle;
		for (let question_datum of question_data)
		{
			if (question_datum.title === qtitle) {qdata = question_datum; break;}
		}
		if (qdata==null && !updated)
		{
			console.log("Fetching question data for", qtitle);
			question_data = await getAllQuestions(update=true);
			treeData.push({
				path: `question_data.json`,
				mode: "100644",
				content: JSON.stringify(question_data)
			})
			updated=true;
		}
		for (let question_datum of question_data)
		{
			if (question_datum.title === qtitle) {qdata = question_datum; break;}
		}
		if (qdata==null) continue;
		else merged_data.push({...post_data[i], ...qdata});
	}
    // let merged_data = JSON.parse(fs.readFileSync("jsons/merged_data.json"))
	let allTags = []
    for(let qa of merged_data)
    {
        let qtitle = qa.questionTitle;
        let qtags = [];
        for (let qtag of qa.topicTags) qtags.push(qtag.name);
        let qcontent = qa.content;
        let qdifficulty = qa.difficulty;
        let atitle = qa.post_data.title;
        let atags = [];
        for (let atag of qa.post_data.solutionTags) atags.push(atag.name);
        let acontent = qa.post_data.post.content;
        let adate = qa.post_data.post.creationDate;

        if (atags.includes("Java")) acontent = acontent.replace(/```((\n|.)*?)```/g, " {% highlight java %} $1 {% endhighlight %}");
        if (atags.includes("Javascript")) acontent = acontent.replace(/```((\n|.)*?)```/g, " {% highlight javascript %} $1 {% endhighlight %}");
        if (atags.includes("Python")) acontent = acontent.replace(/```((\n|.)*?)```/g, " {% highlight python %} $1 {% endhighlight %}");;
        if (atags.includes("Python3")) acontent = acontent.replace(/```((\n|.)*?)```/g, " {% highlight python %} $1 {% endhighlight %}");
        if (atags.includes("C++")) acontent = acontent.replace(/```((\n|.)*?)```/g, " {% highlight cpp %} $1 {% endhighlight %}");
        acontent = acontent.replace(/\{\{/g, '{ {').replace(/\}\}/g, '} }').replace(/\\r/g, '')

        let tags = [];
        for (let qtag of qtags) tags.push(qtag);
        for (let atag of atags) tags.push(atag);
        tags.push(qdifficulty);
		tags = Array.from(new Set(tags));
        // console.log(qtitle, atitle, adate, tags);
        // console.log(qcontent);
        // console.log(acontent);
		adate = (new Date(adate*1000)).toISOString().split('T')[0];
		let tagstr = '["'+tags.join('", "')+'"]';
		let node = {
			path: `_posts/${adate}-${qtitle.toLowerCase().replace(/\//g,'-').replace(/\"/g,'')}-${atitle.toLowerCase().replace(/\//g,'-').replace(/\"/g,'')}.md`,
			mode: "100644",
			content: ['---', 'layout: mypost', `title: "${qtitle.replace(/\"/g,'')} - ${atitle.replace(/\"/g,'')}"`, `tags: ${tagstr}`, '---', "# Problem Statement:", qcontent, "# Solution:", acontent].join('\n')
		};
		treeData.push(node);
		allTags = allTags.concat(tags)
	}
	for (let tag of (new Set(allTags)))
	{		
		treeData.push(
			{
				path: `_tag/${tag}.md`,
				mode: "100644",
				content: ['---', 'layout: tag', `tag-name: ${tag}`, '---'].join('\n'),
			}
		);
	}
	// console.log(treeData);
	let refData = await octokit.git.getRef({
		owner: owner,
		repo: repo,
		ref: `heads/${blog_branch}`,
	});
	let commitData = await octokit.git.getCommit({
			owner: owner,
			repo: repo,
			commit_sha: refData.data.object.sha
	});
	let treeResponse = await octokit.git.createTree({
		owner: owner,
		repo: repo,
		tree: treeData,
		base_tree: commitData.data.tree.sha
	});
	let commitResponse = await octokit.git.createCommit({
		owner: owner,
		repo: repo,
		message: `${commit_message} - ${new Date().toUTCString()}`,
		tree: treeResponse.data.sha,
		parents: [refData.data.object.sha]
	});
	await octokit.git.updateRef({
		owner: owner,
		repo: repo,
		sha: commitResponse.data.sha,
		ref: 'heads/' + blog_branch,
		force: true
	});
	console.log("Done.");
}

sync();
