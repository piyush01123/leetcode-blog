---
layout: mypost
title: "Maximum Number of Jumps to Reach the Last Index - DP based solution"
tags: ["Array", "Dynamic Programming", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of <code>n</code> integers and an integer <code>target</code>.</p>

<p>You are initially positioned at index <code>0</code>. In one step, you can jump from index <code>i</code> to any index <code>j</code> such that:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code></li>
	<li><code>-target &lt;= nums[j] - nums[i] &lt;= target</code></li>
</ul>

<p>Return <em>the <strong>maximum number of jumps</strong> you can make to reach index</em> <code>n - 1</code>.</p>

<p>If there is no way to reach index <code>n - 1</code>, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,6,4,1,2], target = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1. 
- Jump from index 1 to index 3.
- Jump from index 3 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 3 jumps. Hence, the answer is 3. </pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,6,4,1,2], target = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1.
- Jump from index 1 to index 2.
- Jump from index 2 to index 3.
- Jump from index 3 to index 4.
- Jump from index 4 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 5 jumps. Hence, the answer is 5. </pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,6,4,1,2], target = 0
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be proven that there is no jumping sequence that goes from 0 to n - 1. Hence, the answer is -1. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length == n &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= target &lt;= 2 * 10<sup>9</sup></code></li>
</ul>

# Solution:
First step in such problem is to write a recursive function and check validity for small inputs.
 {% highlight cpp %} 
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target, int cur=0) 
    {
        if (cur==nums.size()-1) return 0;
        int res = -1;
        for (int i=cur+1; i<nums.size(); i++) 
            if (abs(nums[i]-nums[cur])<=target && maximumJumps(nums, target, i)>=0)
                res = max(res, 1+maximumJumps(nums, target, i));
        return res;
    }
};
 {% endhighlight %}

Next step is to add memoization:
 {% highlight cpp %} 
class Solution {
   vector<int> memo = vector<int>(10001,-2);
public:
    int maximumJumps(vector<int>& nums, int target, int cur=0) 
    {
        if (cur==nums.size()-1) return 0;
        if (memo[cur]!=-2) return memo[cur];
        int res = -1;
        for (int i=cur+1; i<nums.size(); i++) if (abs(nums[i]-nums[cur])<=target)
        {
            int res_i = maximumJumps(nums, target, i);
            if (res_i!=-1) res = max(res, 1+res_i);
        }            
        return memo[cur] = res;
    }
};
 {% endhighlight %}
We get AC at this point.

Bottom-up DP is another way to get AC. But sometimes this might be difficult.
 {% highlight cpp %} 
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[n-1] = 0;
        for (int i=n-2; i>=0; i--)
        {
            for (int j=i+1; j<n; j++) 
                if (abs(nums[j]-nums[i])<=target && dp[j]>=0)
                    dp[i] = max(dp[i], 1+dp[j]);                
        }
        return dp[0];
    }
};
 {% endhighlight %}