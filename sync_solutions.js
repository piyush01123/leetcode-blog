const axios = require('axios');
const fs = require('fs');
const { Octokit } = require('@octokit/rest');
const core = require('@actions/core');
const { context } = require('@actions/github');
const randomWords = require('random-words');
const glob = require("glob");
const path = require('path');
const { join } = require('path');

const maxRetries = 8; // Number of times to do GET on LC api
const commit_message = 'Sync LeetCode submission';
const lang_to_extension = {   'bash': 'sh',   'c': 'c',   'cpp': 'cpp',   'csharp': 'cs',   'dart': 'dart',   'golang': 'go',   'java': 'java',   'javascript': 'js',   'kotlin': 'kt',   'mssql': 'sql',   'mysql': 'sql',   'oraclesql': 'sql',   'php': 'php',   'python': 'py',   'python3': 'py',   'ruby': 'rb',   'rust': 'rs',   'scala': 'scala',   'swift': 'swift',   'typescript': 'ts', };
const solutions_branch = "lcblog"
const owner = context.repo.owner;
const repo = context.repo.repo;
const leetcodeCSRFToken = process.env.LEETCODE_CSRF_TOKEN;
const leetcodeSession = process.env.LEETCODE_SESSION;
const githubToken = process.env.GITHUB_TOKEN;
const octokit = new Octokit({
	auth: githubToken,
	userAgent: 'LeetCode sync to GitHub - GitHub Action',
});


async function getAllSubmissions(lastTimestamp)
{
	let end = false;
	let offset = 0;
	let allSubmissions = [];
	while (true)
	{
		const config = {
			params: {
				offset: offset,
				limit: 20,
				lastkey: (offset==0?'':response.data.last_key)
			},
			headers: {
				'X-Requested-With': 'XMLHttpRequest',
				'X-CSRFToken': leetcodeCSRFToken,
				'Cookie': `csrftoken=${leetcodeCSRFToken};LEETCODE_SESSION=${leetcodeSession};`
			}
		};
		var response = null;
		var retries = 0;
		while(response==null && retries<maxRetries)
		{
			try {response = await axios.get('https://leetcode.com/api/submissions/', config);
			} catch (exception)
			{
				console.log('Error fetching submissions, retrying in ' + 3 ** retries + ' seconds...');
				await new Promise(r => setTimeout(r, 3 ** retries * 1000));
				retries ++;
			}
			if (response!=null || retries==maxRetries) break;
		}
		if (response==null) return;
		// fs.writeFile(`./jsons/lc_${Date.now()}_${offset/20}.json`, JSON.stringify(response.data), err=>{});
		for (let submission of response.data.submissions_dump)
		{
			if (submission.timestamp < lastTimestamp)
			{
				end = true;
				break;
			}
			if (submission.status_display !== 'Accepted') continue;
			allSubmissions.push(submission);
		}
		if (end) break;
		console.log("Processing", offset/20);
		if (!response.data.has_next) break;
		offset += 20;
	}
	// fs.writeFile('./jsons/leetcodeSubmissions_${Date.now()}.json', JSON.stringify(allSubmissions), err=>{});
	return allSubmissions;
}


async function getLastTimestamp()
{
	let branches = await octokit.repos.listBranches({
		owner: owner,
		repo: repo
	});
	let branchNames = [];
	for (let branch of branches.data) branchNames.push(branch.name);
	if (!branchNames.includes(solutions_branch)) return 0;
	let commits = await octokit.repos.listCommits({
		owner: owner,
		repo: repo,
		per_page: 100,
		sha: solutions_branch
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
		sha: solutions_branch,
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
		ref: 'refs/heads/' + solutions_branch,
		force: true
	});
	await octokit.git.updateRef({
		owner: owner,
		repo: repo,
		sha: commitResponse.data.sha,
		ref: 'heads/' + solutions_branch,
		force: true
	});
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
	if (!branchNames.includes(solutions_branch)) await initBranch();

	let lastTimestamp = await getLastTimestamp();
	let question_data = await getAllQuestions();
	let post_data = await getAllSolutions(lastTimestamp);
	let merged_data = [];
	for (let i=0; i<post_data.length; i++)
	{
		merged_data.push({
			...post_data[i],
			...(question_data.find((item) => item.title === post_data[i].questionTitle))
		});
	}

    // let merged_data = JSON.parse(fs.readFileSync("jsons/merged_data.json"))
	let treeData = [];
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
	console.log(treeData);
	let refData = await octokit.git.getRef({
		owner: owner,
		repo: repo,
		ref: `heads/${solutions_branch}`,
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
		ref: 'heads/' + solutions_branch,
		force: true
	});
	console.log("Done.");
}

sync();
