---
layout: mypost
title: "Partition Array for Maximum Sum - Top down and bottom up DP"
tags: ["Array", "Dynamic Programming", "C++", "Memoization", "Medium"]
---
# Problem Statement:
<p>Given an integer array <code>arr</code>, partition the array into (contiguous) subarrays of length <strong>at most</strong> <code>k</code>. After partitioning, each subarray has their values changed to become the maximum value of that subarray.</p>

<p>Return <em>the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a <strong>32-bit</strong> integer.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,15,7,9,2,5,10], k = 3
<strong>Output:</strong> 84
<strong>Explanation:</strong> arr becomes [15,15,15,9,10,10,10]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
<strong>Output:</strong> 83
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [1], k = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>

# Solution:
Top Down DP approach: `dp[i]` denotes answer for index `i` after considering all candidates for window sizes from 1 to K going forward. Final answer is `dp[0]`.

 {% highlight cpp %} 
class Solution {
    vector<int>dp;
public:
    int maxSum(vector<int>&A, int K, int N, int index)
    {
        if(index==N) return 0;
        if(dp[index]!=-1) return dp[index];
        int curMax = INT_MIN, res = INT_MIN;
        for(int i=index; i<index+K; i++)
        {
            if(i==N) break;
            curMax = max(curMax, A[i]);
            res = max(res, curMax * (i-index+1) + maxSum(A, K, N, i+1));
        }
        return dp[index] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        dp.resize(n,-1);
        return maxSum(arr,k,n,0);
    }
};
 {% endhighlight %}

Bottom Up DP approach: `dp[i]` denotes answer for index `i` after considering all candidates for window sizes from 1 to K going backward. Final answer is `dp[N-1]`.

 {% highlight cpp %} 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int> dp(n,-1);
        for(int i=0; i<n; i++)
        {
            int curMax = INT_MIN;
            for(int j=i; j>i-k; j--)
            {
                if(j<0) break;
                curMax = max(curMax, arr[j]);
                int candidate = (j>0 ? dp[j-1] : 0) + (i-j+1) * curMax;
                dp[i] = max(dp[i], candidate);
            }
        }
        return dp.back();
    }
};
 {% endhighlight %}
Both the approaches have $O(NK)$ time complexity and $O(N)$ space complexity. But top-down DP is slightly slower because of the load caused by the call stack.


![Screenshot 2024-02-03 at 11.06.19 AM.png](https://assets.leetcode.com/users/images/d5fb3228-68cc-4c04-8796-e654dede8c7f_1706938606.3706944.png)
