---
layout: mypost
title: "Combination Sum II - DFS  Recursion"
tags: ["Array", "Backtracking", "C++", "Depth-First Search", "Recursion", "Medium"]
---
# Problem Statement:
<p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sum to <code>target</code>.</p>

<p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p>

<p><strong>Note:</strong>&nbsp;The solution set must not contain duplicate combinations.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> candidates = [10,1,2,7,6,1,5], target = 8
<strong>Output:</strong> 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> candidates = [2,5,2,1,2], target = 5
<strong>Output:</strong> 
[
[1,2,2],
[5]
]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= 30</code></li>
</ul>

# Solution:
The approach is to run DFS starting with zeroth index. At every index, we either 
- include it and run DFS again with reduced target and next index (since repetition is not allowed), OR
- skip current and next indices till we get a different value and then start DFS with the first index which has a different value and with the same target.

 {% highlight cpp %} 
class Solution {
public:
    void dfs(int t, int idx, vector<vector<int>>&res, vector<int>&r, vector<int>&nums)
    {
        if (t==0){res.push_back(r); return;}
        if (t<0 || idx==nums.size()) return;
        r.push_back(nums[idx]);
        dfs(t-nums[idx], idx+1, res, r, nums);
        r.pop_back();
        idx++;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        dfs(t, idx, res, r, nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        for(int k: candidates) cout<<k<<','; cout<<endl;
        vector<vector<int>>res;
        vector<int>r;
        dfs(target, 0, res, r, candidates);
        return res;
        return vector<vector<int>>(res.begin(),res.end());
    }
};
 {% endhighlight %}

$TC: O(2^n), SC: O(2^n)$