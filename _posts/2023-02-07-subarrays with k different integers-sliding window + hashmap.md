---
layout: mypost
title: "Subarrays with K Different Integers - Sliding window + HashMap"
tags: ["Array", "Hash Table", "Sliding Window", "Counting", "C++", "Hard"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of <strong>good subarrays</strong> of </em><code>nums</code>.</p>

<p>A <strong>good array</strong> is an array where the number of different integers in that array is exactly <code>k</code>.</p>

<ul>
	<li>For example, <code>[1,2,3,1,2]</code> has <code>3</code> different integers: <code>1</code>, <code>2</code>, and <code>3</code>.</li>
</ul>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,3], k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3,4], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= nums.length</code></li>
</ul>

# Solution:
We solve the problem of subarray with at most K distinct integers and use it for K and K-1 to get the answer.


 {% highlight cpp %} 
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
    int atMostK(vector<int>& nums, int k) 
    {
        int n = nums.size(), i=0, res=0;
        unordered_map<int,int> H;
        for (int j=0; j<n; j++)
        {
            H[nums[j]]++;
            while(H.size()>k)
            {
                H[nums[i]]--;
                if (H[nums[i]]==0) H.erase(nums[i]);
                i++;
            }
            res += (j-i+1);
        }
        return res;
    }
};
 {% endhighlight %}