---
layout: mypost
title: "Largest Divisible Subset - DP faster than 95%"
tags: ["Array", "Math", "Dynamic Programming", "Sorting", "Medium"]
---
# Problem Statement:
<p>Given a set of <strong>distinct</strong> positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:</p>

<ul>
	<li><code>answer[i] % answer[j] == 0</code>, or</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>If there are multiple solutions, return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,3] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4,8]
<strong>Output:</strong> [1,2,4,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>

# Solution:
The solution is similar to O(N^2) solution for LIS except that we also have to do backtracking, so we maintain 2 values per item in DP: the maximum size of sequence ending at that index and the index of the number it is a multiple of.

```
bool cmp(pair<int,int>a, pair<int,int>b)
{
    return a.first<b.first;
}

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> dp(n,{1,-1});
        for (int i=1; i<n; i++)            
            for (int j=0; j<i; j++)
                if (nums[i]%nums[j]==0 && 1+dp[j].first>dp[i].first)
                    dp[i] = {1+dp[j].first,j};
        auto it = max_element(dp.begin(),dp.end(),cmp);
        auto p = *it;
        vector<int> res{nums[it-dp.begin()]};
        while(p.second>=0)
        {
            res.push_back(nums[p.second]);
            p = dp[p.second];
        }
        return res;
    }
};
```
This is faster than 95% of solutions:
```
Runtime: 52 ms, faster than 95.12% of C++ online submissions for Largest Divisible Subset.
Memory Usage: 8.9 MB, less than 46.13% of C++ online submissions for Largest Divisible Subset.
```

I'm reproducing the O(N^2) solution of LIS for clarity:
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for (int i=0; i<n; i++)
            for (int j=0; j<i; j++)
                if (nums[i]>nums[j])
                    dp[i] = max(dp[j]+1,dp[i]);
        return *max_element(dp.begin(),dp.end());
    }
};
```

For more details on LIS algorithm refer [here](https://leetcode.com/problems/longest-increasing-subsequence/discuss/2660000/Two-DP-solutions).