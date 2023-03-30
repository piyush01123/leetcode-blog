---
layout: mypost
title: "Wiggle Sort II - Trial and Error"
tags: ["Array", "Divide and Conquer", "Sorting", "Quickselect", "C++", "Medium"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code>, reorder it such that <code>nums[0] &lt; nums[1] &gt; nums[2] &lt; nums[3]...</code>.</p>

<p>You may assume the input array always has a valid answer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,1,1,6,4]
<strong>Output:</strong> [1,6,1,5,1,4]
<strong>Explanation:</strong> [1,4,1,5,1,6] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2,2,3,1]
<strong>Output:</strong> [2,3,1,3,1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5000</code></li>
	<li>It is guaranteed that there will be an answer for the given input <code>nums</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow Up:</strong> Can you do it in <code>O(n)</code> time and/or <strong>in-place</strong> with <code>O(1)</code> extra space?
# Solution:
My first attempt was to do alternate from front (first even 0,2,4,.. indices then odd 1,3,5,... indices) ie
`0,1,2,3,4,5` becomes `0,3,1,4,2,5` and `0,1,2,3,4` becomes `0,3,1,4,2`. 
 {% highlight cpp %} 
void wiggleSort(vector<int>& nums) 
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> arr(n, 0);
    for (int i=0; i<n; i+=2)
        arr[n-1-i] = nums[(n+i)/2]; 
    for (int i=1; i<n; i+=2)
        arr[n-1-i] = nums[i/2];
    nums = arr;
}
 {% endhighlight %}
However this fails for `4,5,5,6` because it will give us `4,5,5,6`. 
Notice however that alternate from back works ie `5,6,4,5` (again even indices R to L then odd indices R to L). A few more tests should tell you that this is a valid algorithm. Hence gives us an AC. However we have to take special care of whether array size is even or odd. 

 {% highlight cpp %} 
void wiggleSort(vector<int>& nums) 
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> arr(n, 0);
    for (int i=0; i<n; i+=2)
        arr[i] = nums[(n-i)/2 - (n%2==0 ? 1 : 0)];
    for (int i=1; i<n; i+=2)
        arr[i] = nums[n-1-i/2];
    nums = arr;
}
 {% endhighlight %}