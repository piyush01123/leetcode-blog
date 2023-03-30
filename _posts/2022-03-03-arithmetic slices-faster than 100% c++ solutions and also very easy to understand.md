---
layout: mypost
title: "Arithmetic Slices - Faster than 100% C++ solutions and also very easy to understand"
tags: ["Array", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>An integer array is called arithmetic if it consists of <strong>at least three elements</strong> and if the difference between any two consecutive elements is the same.</p>

<ul>
	<li>For example, <code>[1,3,5,7,9]</code>, <code>[7,7,7,7]</code>, and <code>[3,-1,-5,-9]</code> are arithmetic sequences.</li>
</ul>

<p>Given an integer array <code>nums</code>, return <em>the number of arithmetic <strong>subarrays</strong> of</em> <code>nums</code>.</p>

<p>A <strong>subarray</strong> is a contiguous subsequence of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

# Solution:
Given you have a arithmetic sequence (AS) of length 4 as in the example, you can quickly see that:
- Number of AS of length 3 = (4-3+1)=2
- Number of AS of length 4 = (4-4+1)=1

Hence, Number of AS = 2+1 = 3

You can extend this logic to this:
**Given an AS of maximum length L, `total number of AS=1+2+3+..+L-2 = 1/2*(L-2)*(L-1)`**

So, what we need to do is as we traverse through the array, find out the AS (we keep moving the 2nd pointer till the AS is finished) and then calculate the total number of AS using above formula. 

Now for the fun part:

 {% highlight cpp %} 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(), i=0, res=0;
        while (i<n-2)
        {
            int start=i;
            while (i<n-2 && nums[i+1]-nums[i]==nums[i+2]-nums[i+1]) i++;
            int L = i+2-start;
            int num_subs = (L-2)*(L-1)/2;
            res += num_subs;
            i++;
        }
        return res;
    }
};
 {% endhighlight %}