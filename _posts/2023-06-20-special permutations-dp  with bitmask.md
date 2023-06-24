---
layout: mypost
title: "Special Permutations - DP  with bitmask"
tags: ["Array", "Dynamic Programming", "Bit Manipulation", "Bitmask", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given a&nbsp;<strong>0-indexed</strong>&nbsp;integer array&nbsp;<code>nums</code>&nbsp;containing&nbsp;<code>n</code>&nbsp;<strong>distinct</strong> positive integers. A permutation of&nbsp;<code>nums</code>&nbsp;is called special if:</p>

<ul>
	<li>For all indexes&nbsp;<code>0 &lt;= i &lt; n - 1</code>, either&nbsp;<code>nums[i] % nums[i+1] == 0</code>&nbsp;or&nbsp;<code>nums[i+1] % nums[i] == 0</code>.</li>
</ul>

<p>Return&nbsp;<em>the total number of special permutations.&nbsp;</em>As the answer could be large, return it&nbsp;<strong>modulo&nbsp;</strong><code>10<sup>9&nbsp;</sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,6]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [3,6,2] and [2,6,3] are the two special permutations of nums.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [3,1,4] and [4,1,3] are the two special permutations of nums.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 14</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
Here is the baseline solution:
 {% highlight cpp %} 
class Solution {
public:
    int helper(vector<int>&nums, int cur, int mask, int n)
    {
        if (mask+1==(1<<n)) return 1;
        int res=0;
        for(int i=0; i<n; i++)
            if (((mask&(1<<i))==0) &&  ((nums[i]%nums[cur]==0)||(nums[cur]%nums[i]==0)))
                res += helper(nums, i, (mask|(1<<i)), n);
        return res;
    }
    int specialPerm(vector<int>& nums) 
    {
        int n = nums.size(), res=0;
        for (int i=0; i<n; i++)res += helper(nums, i, (1<<i), n);
        return res;
    }
};

 {% endhighlight %}
We start counting at each index `i` and start with the bitmask `(1<<i)`. Bitmask denotes the indexes which have been already included. So, this is like counting permutations starting from each index one by one. 

When we have included every index, then the `mask` reaches a state `11...1` and the answer for this state is 1. This signifies that we have successfully created a permutation.

Given any current index `cur` and a `mask` denoting incuded indexes, we have two conditions to include a new index `i` in permutation:
- It must not have been already included. For this the condition is `(mask & (1<<i))==0`
- The condition of  mod with current element must be zero. For this we have `(nums[i]%nums[cur]==0) || (nums[cur]%nums[i]==0)`

Finally let us add memoization and overflow steps to get AC.

 {% highlight cpp %} 
class Solution {
    vector<vector<int>> dp;
    int mod=1e9+7;
public:
    int helper(vector<int>&nums, int cur, int mask, int n)
    {
        if (dp[cur][mask]!=-1) return dp[cur][mask];
        if (mask+1==(1<<n)) return dp[cur][mask]=1;
        int res=0;
        for(int i=0; i<n; i++)
        {
            // not included till now and condition is met
            if (((mask&(1<<i))==0) &&  ((nums[i]%nums[cur]==0)||(nums[cur]%nums[i]==0)))
            {
                res += helper(nums, i, (mask|(1<<i)), n)  %  mod;
                res %= mod;
            }
        }
        return dp[cur][mask] = res;
    }
    int specialPerm(vector<int>& nums) 
    {
        int n = nums.size(), res=0;
        dp = vector<vector<int>>(n+1, vector<int>((1<<n)+1, -1));
        for (int i=0; i<n; i++)
        {
            res += helper(nums, i, (1<<i), n)  %  mod;
            res %= mod;
        }
        return res;
    }
};

 {% endhighlight %}

TC: $O(n * 2^n)$, SC: $O(n * 2^n)$