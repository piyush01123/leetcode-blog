---
layout: mypost
title: "Next Permutation - Well-explained O(n) easy to understand in C++"
tags: ["Array", "Two Pointers", "C", "Medium"]
---
# Problem Statement:
<p>A <strong>permutation</strong> of an array of integers is an arrangement of its members into a sequence or linear order.</p>

<ul>
	<li>For example, for <code>arr = [1,2,3]</code>, the following are all the permutations of <code>arr</code>: <code>[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]</code>.</li>
</ul>

<p>The <strong>next permutation</strong> of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the <strong>next permutation</strong> of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).</p>

<ul>
	<li>For example, the next permutation of <code>arr = [1,2,3]</code> is <code>[1,3,2]</code>.</li>
	<li>Similarly, the next permutation of <code>arr = [2,3,1]</code> is <code>[3,1,2]</code>.</li>
	<li>While the next permutation of <code>arr = [3,2,1]</code> is <code>[1,2,3]</code> because <code>[3,2,1]</code> does not have a lexicographical larger rearrangement.</li>
</ul>

<p>Given an array of integers <code>nums</code>, <em>find the next permutation of</em> <code>nums</code>.</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a></strong> and use only constant extra memory.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,3,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> [1,2,3]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,5]
<strong>Output:</strong> [1,5,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

# Solution:
Steps:
- Traverse through the array right to left, starting from `n-2` position (`n` is length of array)
- If you find `a[i+1]>a[i]` stop.
- If you reached `i=-1` means array is sorted in decreasing order. Reverse the whole array and return. Else follow next steps
- Now remember that to the right of `i` we have decreasing sorted array (from `i+1` to `n-1`)
- Reverse the array from `i+1` to `n-1` to make it increasing sorted.
- Find the smallest number greater than `a[i]` in this portion and swap with `a[i]`. Remember there will always be at least one number greater than `a[i]` here because when you had stopped traversing, you had `a[i+1]>a[i]`, so at least that `a[i+1]` will still be there, but there still might be another more suitable candidate.
- You are done!

For example
```
A = [9,8,4,8,6,4,3]
```
You will stop at `i=2` because for the first time from right to left, `A[i+1]>A[i]`
Now we see that we have a decreasing sorted array to the right of `i=2`: `[8,6,4,3]`. Reverse this part, so A now becomes:
```
A = [9,8,4,3,4,6,8]
```
Now traverse from `i=3` to end of array to find smallest number greater than `A[2]=4` and swap with `A[2]`. So we will have:
```
A=[9,8,6,3,4,4,8]
```
This is indeed the correct answer.

Coding it up:
```
class Solution {
public:
    void swap(int &a, int&b)
    {
        int t=a;
        a=b;
        b=t;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1) return;
        int n=nums.size(), i;
        for (i=n-2; i>=0; i--)
            if (nums[i+1]>nums[i]) break;
        if (i==-1) {reverse(nums.begin(),nums.end()); return;}
        sort(nums.begin()+i+1, nums.end());
        int j;
        for (j=i+1; j<n; j++) if (nums[j]>nums[i]) break;
        swap(nums[i],nums[j]);
        return;
    }
};
```