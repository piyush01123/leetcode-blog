---
layout: mypost
title: "Valid Triangle Number - O(N^2) log(N) Binary Search [AC]"
tags: ["Array", "Two Pointers", "Binary Search", "Greedy", "Sorting", "C++", "Binary Tree", "Medium"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code>, return <em>the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,2,3,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

# Solution:
Firstly sort `nums`.
Now chose 1st two sides of triangle in for loop. 
Say `a=nums[i], b=nums[j]` where `i<j`. 
For the 3rd side of the triangle, check the lowest index where `a+b` or any number greater than that occurs in case `a+b` is absent. Call this index as `k`.
Then, valid triangles can be with chosen `a`, `b` and  `c` can be chosen from index between indices `j` and `k`.


 {% highlight cpp %} 
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), res=0;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                auto it = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                int pos = it-nums.begin();
                if (pos-j-1>0) res+=(pos-j-1);
            }
        }
        return res;
    }
};
 {% endhighlight %}