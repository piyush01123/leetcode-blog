---
layout: mypost
title: "Find Minimum in Rotated Sorted Array - Iterative binary search"
tags: ["Array", "Binary Search", "C++", "Medium"]
---
# Problem Statement:
<p>Suppose an array of length <code>n</code> sorted in ascending order is <strong>rotated</strong> between <code>1</code> and <code>n</code> times. For example, the array <code>nums = [0,1,2,4,5,6,7]</code> might become:</p>

<ul>
	<li><code>[4,5,6,7,0,1,2]</code> if it was rotated <code>4</code> times.</li>
	<li><code>[0,1,2,4,5,6,7]</code> if it was rotated <code>7</code> times.</li>
</ul>

<p>Notice that <strong>rotating</strong> an array <code>[a[0], a[1], a[2], ..., a[n-1]]</code> 1 time results in the array <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code>.</p>

<p>Given the sorted rotated array <code>nums</code> of <strong>unique</strong> elements, return <em>the minimum element of this array</em>.</p>

<p>You must write an algorithm that runs in&nbsp;<code>O(log n) time.</code></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,5,1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The original array was [1,2,3,4,5] rotated 3 times.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,5,6,7,0,1,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [11,13,15,17]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The original array was [11,13,15,17] and it was rotated 4 times. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
	<li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is sorted and rotated between <code>1</code> and <code>n</code> times.</li>
</ul>

# Solution:
Notice that to verify if an array element is minimum or not, it is sufficient to verify that it is smaller than both its neighbors (with rotation).ie
 {% highlight cpp %} 
prev = (mid==0) ? n-1 : mid-1
next = (mid==n-1) ? 0 : mid+1
A[mid]<=A[prev] and A[mid]<=A[next]
 {% endhighlight %}
We want to find an index `mid` in the range `[0,n)` that satisfies this condition. We use binary search for this.

 {% highlight cpp %} 
int findMin(vector<int>& nums) 
{
	int n=nums.size(), lo=0, hi=n-1, mid;
	while (lo<=hi)
	{
		mid = lo + (hi-lo)/2;
		int prev = (mid-1+n)%n, next = (mid+1)%n;
		if (nums[mid]<=nums[prev] && nums[mid]<=nums[next])
			break;
		else if (nums[mid] <= nums[hi])
			hi = mid-1;
		else
			lo = mid+1; // nums[0...mid] subarray is sorted
	}
	return nums[mid];
}
 {% endhighlight %}