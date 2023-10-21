---
layout: mypost
title: "Constrained Subsequence Sum - Sliding window DP with heap"
tags: ["Array", "Dynamic Programming", "Queue", "Sliding Window", "Heap (Priority Queue)", "Monotonic Queue", "C++", "Hard"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the maximum sum of a <strong>non-empty</strong> subsequence of that array such that for every two <strong>consecutive</strong> integers in the subsequence, <code>nums[i]</code> and <code>nums[j]</code>, where <code>i &lt; j</code>, the condition <code>j - i &lt;= k</code> is satisfied.</p>

<p>A <em>subsequence</em> of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,2,-10,5,20], k = 2
<strong>Output:</strong> 37
<b>Explanation:</b> The subsequence is [10, 2, 5, 20].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,-3], k = 1
<strong>Output:</strong> -1
<b>Explanation:</b> The subsequence must be non-empty, so we choose the largest number.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,-2,-10,-5,20], k = 2
<strong>Output:</strong> 23
<b>Explanation:</b> The subsequence is [10, -2, -5, 20].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
Let `dp[i]` be the solution for the prefix of the array that ends at index `i`, if the element at index `i` is in the subsequence. Then we have the following relation:

 {% highlight cpp %} 
dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])
 {% endhighlight %}

Now to get the maximum of a sliding window, we maintain a max heap. The heap has no constraint on size but we enforce the constraint that the heap top is within the current sliding window.

 {% highlight cpp %} 
class Solution 
{
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq; //(value,index)
        vector<int> dp(nums.size());
        for (int i=0; i<nums.size(); i++)
        {
            while(!pq.empty() && pq.top().second < i-k) pq.pop(); 
            dp[i] = nums[i] + ( i==0 ? 0 : max(0,pq.top().first) );
            pq.push({dp[i],i});
        }
        return *max_element(dp.begin(),dp.end());
    }
};
 {% endhighlight %}

TC: $O(n \log(n))$, SC: $O(n)$. 

Worst case is when the array is sorted in increasing order, hence the heap size is $n$.