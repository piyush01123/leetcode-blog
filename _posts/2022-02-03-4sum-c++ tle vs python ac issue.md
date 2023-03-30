---
layout: mypost
title: "4Sum - C++ TLE vs Python AC issue"
tags: ["Array", "Two Pointers", "Sorting", "Medium"]
---
# Problem Statement:
<p>Given an array <code>nums</code> of <code>n</code> integers, return <em>an array of all the <strong>unique</strong> quadruplets</em> <code>[nums[a], nums[b], nums[c], nums[d]]</code> such that:</p>

<ul>
	<li><code>0 &lt;= a, b, c, d&nbsp;&lt; n</code></li>
	<li><code>a</code>, <code>b</code>, <code>c</code>, and <code>d</code> are <strong>distinct</strong>.</li>
	<li><code>nums[a] + nums[b] + nums[c] + nums[d] == target</code></li>
</ul>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
<strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2,2,2], target = 8
<strong>Output:</strong> [[2,2,2,2]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
I have noticed several times that I am getting TLE while solving a problem in C++. Then when I write the exact same algorithm in python I get an AC. This could be because LC allows more time for python. Does this mean anything? Is it better to switch to python for this reason?

Evidence:
[4-Sum](https://leetcode.com/problems/4sum) throws TLE in C++ for this:
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                unordered_set<int> S;
                for (int k=j+1; k<n; k++)
                {
                    if (S.count(nums[k])) 
                    {
                        vector<int>quad {nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]};
                        sort(quad.begin(),quad.end());
                        if (find(res.begin(), res.end(), quad)==res.end()) res.push_back(quad);
                    }
                    S.insert(target-nums[i]-nums[j]-nums[k]);
                }
            }
        }
        return res;
    }
};
```
but passes in python for this which is exactly the same.
```
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(n):
            for j in range(i+1,n):
                S = set()
                for k in range(j+1,n):
                    if nums[k] in S:
                        quad = [nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]]
                        quad.sort()
                        if quad not in res:
                            res.append(quad)
                    S.add(target-nums[i]-nums[j]-nums[k])
        return res
```