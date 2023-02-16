# Leetcode Solutions
This repository contains all my leetcode solutions (AC) on the branch `leetcode`. You can use this repo to sync your own leetcode solutions.

## How to use
1. Fork this repo (default branch `syncer` only)
2. Save secrets `LEETCODE_CSRF_TOKEN` and `LEETCODE_SESSION`. To get these sign-in on leetcode and copy from cookies for `/api/home`. Here is an example.
<p align="center">
<img src="https://user-images.githubusercontent.com/19518507/219264006-bc0fe23f-ccf0-4c24-9519-1ce3754b8ed4.png" height="400">
</p>

3. Go to Actions -> Sync My Leetcode Submissions -> Run workflow. Refesh to see logs.

# Credits
This repo is inspired from https://github.com/joshcai/leetcode-sync. I have made the code more readable and easier to work on if required. Also does not need to create new Github action. I am planning to create a tool to sync LC discussion posts into a blog.