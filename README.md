# Leetcode Blog
This is a tool to sync your leetcode discussion posts into an automatically generated blog. My blog is present at https://piyush01123.github.io/leetcode-blog. The blog has tags on each post and one can look up all the posts having a specific tag. Here are some screenshots:

| | |
|-|-|
![Screenshot 2023-03-31 at 6 48 39 AM](https://user-images.githubusercontent.com/19518507/228999343-923f9878-d22c-41eb-820e-8919b81df09a.png) | ![Screenshot 2023-03-31 at 6 49 52 AM](https://user-images.githubusercontent.com/19518507/228999335-d374b474-c1b3-4c80-9e3b-94aa4057dd87.png)
![Screenshot 2023-03-31 at 6 52 08 AM](https://user-images.githubusercontent.com/19518507/228999318-8618de89-a601-43db-9452-15af1ef96ea3.png) | ![Screenshot 2023-03-31 at 6 50 10 AM](https://user-images.githubusercontent.com/19518507/228999328-0f152fea-b601-428e-a86f-06903c3672bd.png) | 

## How to create your own leetcode blog
1. Fork this repo. **Make sure to choose default branch `master` only**
2. Save secrets `LEETCODE_CSRF_TOKEN`, `LEETCODE_SESSION` and `LEETCODE_ID`. To get the first two, sign-in on leetcode and copy from cookies for `/api/home`. Here is an example. The third one is your username on leetcode.
<p align="center">
<img src="https://user-images.githubusercontent.com/19518507/219264006-bc0fe23f-ccf0-4c24-9519-1ce3754b8ed4.png" height="400">
</p>

3. To save these as repo secrets, go to repo settings -> secrets and variables -> actions -> new repository secret and save the 3 variables `LEETCODE_CSRF_TOKEN`, `LEETCODE_SESSION` and `LEETCODE_ID`.
4. Go to Actions -> Sync My Leetcode Submissions -> Run workflow. Refesh to see logs. You can now verify that you have 3 branches `master`, `leetcode` and `lcblog`
5. Go to repo settings -> pages -> build and deployment. Select branch `lcblog`.
6. If everything has worked till now, you should now be able to see your blog at `${github_username}.github.io/leetcode-solutions`. Note that you need to have a working root url (`${github_username}.github.io`). Hopefully you already have a personal webiste on this URL. If not, create a blank website to make the URL active.

*BONUS: It also syncs all your submissions (AC status) into another branch called ac_submissions*

## Customize your leetcode blog
I have created this using [minima](https://github.com/jekyll/minima) theme but you can change the theme or add new plugins etc by tinkering with the [template](/template/) directory. [Jekyll docs](https://jekyllrb.com/docs/) and [Liquid docs](https://shopify.github.io/liquid/) will be helpful to get started.

## Acknowledgement
This project was initially inspired from [here](https://github.com/joshcai/leetcode-sync).
