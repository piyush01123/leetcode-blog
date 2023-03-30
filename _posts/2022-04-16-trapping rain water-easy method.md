---
layout: mypost
title: "Trapping Rain Water - Easy method"
tags: ["Array", "Two Pointers", "Dynamic Programming", "Stack", "Monotonic Stack", "C++", "Hard"]
---
# Problem Statement:
<p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;" />
<pre>
<strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
Water trapped at any point is equal to `min(max_to_the_left, max_to_the_right) - h` where `h` is its own height.
So all we need to do is find out that for each point, what is the maximum height to its left and maximum height to its right. This can be achieved in a fairly easy way: Just traverse through the array Left to Right and keep track of the max element seen. Similarly do the same but from Right to Left.
Finally, we do one last traversal to find the total water accumulated but this time from `1 to n-2` because the elements `0` and `n-1` (first and last) cannot hold water.

 {% highlight cpp %} 
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int curr=0;
        vector<int> maxLtoR(n,0), maxRtoL(n,0);
        for (int i=0; i<n; i++)
        {
            curr = max(curr, height[i]);
            maxLtoR[i] = curr;
        }
        curr = 0;
        for (int i=n-1; i>=0; i--)
        {
            curr = max(curr, height[i]);
            maxRtoL[i] = curr;
        }
        int amt_here, total_amt=0;
        for (int i=1; i<n-1; i++)
        {
            amt_here =  min(maxLtoR[i], maxRtoL[i]) - height[i];
            total_amt += amt_here;
        }
        return total_amt;
    }
};
 {% endhighlight %}

 {% highlight cpp %} 
TC: O(n)
SC: O(n)
 {% endhighlight %}