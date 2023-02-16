const axios = require('axios');
const fs = require('fs');
const { Octokit } = require('@octokit/rest');
const core = require('@actions/core');
const { context } = require('@actions/github');
const randomWords = require('random-words');

const maxRetries = 8; // Number of times to do GET on LC api
const commit_message = 'Sync LeetCode submission';
const lang_to_extension = {   'bash': 'sh',   'c': 'c',   'cpp': 'cpp',   'csharp': 'cs',   'dart': 'dart',   'golang': 'go',   'java': 'java',   'javascript': 'js',   'kotlin': 'kt',   'mssql': 'sql',   'mysql': 'sql',   'oraclesql': 'sql',   'php': 'php',   'python': 'py',   'python3': 'py',   'ruby': 'rb',   'rust': 'rs',   'scala': 'scala',   'swift': 'swift',   'typescript': 'ts', };
const destination_folder = "leetcode_solutions"
const solutions_branch = "leetcode"
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
	let treeResponse = await octokit.git.createTree({
		owner: owner,
		repo: repo,
		sha: solutions_branch,
		tree: [
			{
				"path": "README.md",
				"mode": "100644",
				"content": "# Leetcode Solutions\nThis branch contains all the Leetcode accepted solutions."
			}
		],
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


async function syncSubmissions()
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
	let allSubmissions = await getAllSubmissions(lastTimestamp);
	let treeData = [];
	for (let submission of allSubmissions)
	{
		let name = submission.title.toLowerCase().replace(/\s/g, '_');;
		let prefix = !!destination_folder ? `${destination_folder}/` : '';
		let rand_string = randomWords({exactly: 3, join: '_'});
		let path = `${prefix}${name}/solution_${rand_string}.${lang_to_extension[submission.lang]}`;
		treeData.push(
			{
				path: path,
				mode: '100644',
				content: submission.code
			}
		);
	}

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

syncSubmissions()
