---
layout: mypost
title: "Subarray Sum Equals K - O(N) HashMap cummulative sum"
tags: ["Array", "Hash Table", "Prefix Sum", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the total number of subarrays whose sum equals to</em> <code>k</code>.</p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1], k = 2
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], k = 3
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>

# Solution:
# Algorithm:
- Maintain a HashMap of cummulative sum of array using variable `curr`
- If you see that `curr-k` is in HashMap, add it to the count of contiguous subarrays
- Add `curr` to the HashMap.

 {% highlight cpp %} 
#define ll long long
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), res=0; ll curr=0;
        unordered_map<ll,int> H;
        H[0] = 1; // At i=-1 we have seen 0
        for (int i=0; i<n; i++)
        {
            curr+=nums[i];
            if (H.count(curr-k)) res+=H[curr-k];
            H[curr]++;
        }
        return res;
    }
};
 {% endhighlight %}