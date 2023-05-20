---
layout: mypost
title: "Combination Sum - DFS  Recursion"
tags: ["Array", "Backtracking", "C++", "Depth-First Search", "Recursion", "Medium"]
---
# Problem Statement:
<p>Given an array of <strong>distinct</strong> integers <code>candidates</code> and a target integer <code>target</code>, return <em>a list of all <strong>unique combinations</strong> of </em><code>candidates</code><em> where the chosen numbers sum to </em><code>target</code><em>.</em> You may return the combinations in <strong>any order</strong>.</p>

<p>The <strong>same</strong> number may be chosen from <code>candidates</code> an <strong>unlimited number of times</strong>. Two combinations are unique if the <span data-keyword="frequency-array">frequency</span> of at least one of the chosen numbers is different.</p>

<p>The test cases are generated such that the number of unique combinations that sum up to <code>target</code> is less than <code>150</code> combinations for the given input.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> candidates = [2,3,6,7], target = 7
<strong>Output:</strong> [[2,2,3],[7]]
<strong>Explanation:</strong>
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> candidates = [2,3,5], target = 8
<strong>Output:</strong> [[2,2,2,2],[2,3,3],[3,5]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> candidates = [2], target = 1
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
	<li><code>2 &lt;= candidates[i] &lt;= 40</code></li>
	<li>All elements of <code>candidates</code> are <strong>distinct</strong>.</li>
	<li><code>1 &lt;= target &lt;= 40</code></li>
</ul>

# Solution:
The approach is to run DFS starting with zeroth index. At every index, we either 
- include it and run DFS again with reduced target and same index (since repetition is allowed) , OR 
- skip it and run DFS with original target and next index.

 {% highlight cpp %} 
class Solution {
public:
    void dfs(vector<int>&nums, int target, vector<vector<int>>&res, vector<int>&cur, int start)
    {
        if (target==0){res.push_back(cur);return;}
        if (target<0 || start==nums.size()) return;
        cur.push_back(nums[start]);
        dfs(nums, target-nums[start], res, cur, start);
        cur.pop_back();
        dfs(nums, target, res, cur, start+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<int> r;
        vector<vector<int>> res;
        dfs(candidates, target, res, r, 0);
        return res;
    }
};
 {% endhighlight %}

TC: $O(n^{T/A_{min} }), SC: O(n^{T/A_{min} })$