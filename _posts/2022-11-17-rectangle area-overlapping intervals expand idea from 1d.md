---
layout: mypost
title: "Rectangle Area - Overlapping intervals expand idea from 1D"
tags: ["Math", "Geometry", "C++", "Medium"]
---
# Problem Statement:
<p>Given the coordinates of two <strong>rectilinear</strong> rectangles in a 2D plane, return <em>the total area covered by the two rectangles</em>.</p>

<p>The first rectangle is defined by its <strong>bottom-left</strong> corner <code>(ax1, ay1)</code> and its <strong>top-right</strong> corner <code>(ax2, ay2)</code>.</p>

<p>The second rectangle is defined by its <strong>bottom-left</strong> corner <code>(bx1, by1)</code> and its <strong>top-right</strong> corner <code>(bx2, by2)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Rectangle Area" src="https://assets.leetcode.com/uploads/2021/05/08/rectangle-plane.png" style="width: 700px; height: 365px;" />
<pre>
<strong>Input:</strong> ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
<strong>Output:</strong> 45
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>4</sup> &lt;= ax1 &lt;= ax2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= ay1 &lt;= ay2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= bx1 &lt;= bx2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= by1 &lt;= by2 &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
First let us solve the problem in 1D:
**Given Two intervals (a1,a2) and (b1,b2) find if they are overlapping or not**
Well, the answer is they are overlapping if 
 {% highlight cpp %} 
bool overlap = a1 < b2 && a2 > b1;
 {% endhighlight %}

**What is the length of this overlap?**
Well the length of overlap is
 {% highlight cpp %} 
int L_overlap= min(a2,b2) - max(a1,b1);
 {% endhighlight %}

**So, what is the total length**
 {% highlight cpp %} 
int L1 = (a2-a1),   L2 = (b2-b1);
int L_total = (overlap ? L1+L2-L_overlap : L1+L2);
 {% endhighlight %}

Now we will expand this idea to 2D.
The only crucial difference is that the overlap happens only if the overlap condition is met in both X and Y directions.

C++ code:
 {% highlight cpp %} 
class Solution {
public:
    int area(int x1, int y1, int x2, int y2)
    {
        return (x2-x1) * (y2-y1);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A = area(ax1,ay1,ax2,ay2);
        int B = area(bx1,by1,bx2,by2);        
        bool overlap_x = bx1 < ax2 && bx2 > ax1;
        bool overlap_y = by1 < ay2 && by2 > ay1;
        if (!overlap_x || !overlap_y) return A + B;
        int cx1 = max(ax1,bx1);
        int cy1 = max(ay1,by1);
        int cx2 = min(ax2,bx2);
        int cy2 = min(ay2,by2);
        int C = area(cx1,cy1,cx2,cy2);                
        return A + B - C;
    }
};
 {% endhighlight %}