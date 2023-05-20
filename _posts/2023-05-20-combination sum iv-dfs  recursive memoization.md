---
layout: mypost
title: "Combination Sum IV - DFS  Recursive Memoization"
tags: ["Array", "Dynamic Programming", "C++", "Depth-First Search", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>Given an array of <strong>distinct</strong> integers <code>nums</code> and a target integer <code>target</code>, return <em>the number of possible combinations that add up to</em>&nbsp;<code>target</code>.</p>

<p>The test cases are generated so that the answer can fit in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], target = 4
<strong>Output:</strong> 7
<strong>Explanation:</strong>
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [9], target = 3
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li>All the elements of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?</p>

# Solution:
The approach is to run DFS starting with zeroth index. At each step, we reduce target and re-start DFS from the starting index. This is because, here not just repetition is allowed, but also, the same set of elements with different permutation is considered different.

Here is the recursive solution.
 {% highlight cpp %} 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if (target==0) return 1;
        if (target<0) return 0;
        int cur=0;
        for (int i=0; i<nums.size(); i++)
            cur += combinationSum4(nums, target-nums[i]);
        return cur;
    }
};
 {% endhighlight %}

**Adding memoization**:

 {% highlight cpp %} 
class Solution {
    unordered_map<int,int> memo;
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if (target==0) return 1;
        if (target<0) return 0;
        int cur=0;
        for (int i=0; i<nums.size(); i++)
            if (memo.count(target-nums[i])) cur += memo[target-nums[i]];
            else
                cur += combinationSum4(nums, target-nums[i]);
        return memo[target] = cur;
    }
};
 {% endhighlight %}