# Leetcode Solutions
This is a tool to sync your leetcode discussion posts into an automatically generated blog. My blog is present at https://piyush01123.github.io/leetcode-solutions. The blog has tags on each post and one can look up all the posts with a tag. Here are some screenshots

<!-- <p align="center">
<img src="https://user-images.githubusercontent.com/19518507/221754151-d08cb4a6-d905-44f5-9e31-4ab1fbc2a219.png" height="500">
</p>
 -->
<!-- ![Screenshot 2023-02-28 at 10 10 13 AM](https://user-images.githubusercontent.com/19518507/221755658-54cb99d2-1679-40df-bb57-f593ed7e249a.png)
 -->

&nbsp;             |  &nbsp;
:-------------------------:|:-------------------------:
![](https://user-images.githubusercontent.com/19518507/221754151-d08cb4a6-d905-44f5-9e31-4ab1fbc2a219.png)  |  ![](https://user-images.githubusercontent.com/19518507/221755658-54cb99d2-1679-40df-bb57-f593ed7e249a.png)

This tool will also sync all your submissions (AC status) into another branch.

## How to use
1. Fork this repo. **Make sure to choose default branch `master` only**
2. Save secrets `LEETCODE_CSRF_TOKEN`, `LEETCODE_SESSION` and `LEETCODE_ID`. To get the first two, sign-in on leetcode and copy from cookies for `/api/home`. Here is an example. The third one is your username on leetcode.
<p align="center">
<img src="https://user-images.githubusercontent.com/19518507/219264006-bc0fe23f-ccf0-4c24-9519-1ce3754b8ed4.png" height="400">
</p>

3. To save these as repo secrets, go to repo settings -> secrets and variables -> actions -> new repository secret and save the 3 variables `LEETCODE_CSRF_TOKEN`, `LEETCODE_SESSION` and `LEETCODE_ID`.
4. Go to Actions -> Sync My Leetcode Submissions -> Run workflow. Refesh to see logs. You can now verify that you have 3 branches `master`, `leetcode` and `lcblog`
5. Go to repo settings -> pages -> build and deployment. Select branch `lcblog`.
6. If everything has worked till now, you should now be able to see your blog at `${github_username}.github.io/leetcode-solutions`. Note that you need to have a working root url (`${github_username}.github.io`). Hopefully you already have a personal webiste on this URL. If not, create a blank website to make the URL active.
7. Also all your submissions (AC status) should be present on `leetcode` branch.

## Acknowledgement
This repo is inspired from [here](https://github.com/joshcai/leetcode-sync). The crucial addition is automatic creation of blog. I have made the code easier to work with if required. Also does not need to create a new Github action.
