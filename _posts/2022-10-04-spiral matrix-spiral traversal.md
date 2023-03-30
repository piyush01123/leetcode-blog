---
layout: mypost
title: "Spiral Matrix - Spiral traversal"
tags: ["Array", "Matrix", "Simulation", "C++", "Medium"]
---
# Problem Statement:
<p>Given an <code>m x n</code> <code>matrix</code>, return <em>all elements of the</em> <code>matrix</code> <em>in spiral order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>

# Solution:
Just remember to keep track of start and end indices for x and y directions.
 {% highlight cpp %} 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size(), i=0, j=0;
        int sy=0, sx=0, ey=m, ex=n; // m=ey=3, n=ex=4
        vector<int> res;
        while (res.size() < m*n)
        {
            while (res.size() < m*n && j<ex)
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            j--; i++; ex--;
            while (res.size() < m*n && i<ey)
            {
                res.push_back(matrix[i][j]);
                i++;
            }
            i--; j--; ey--;
            while (res.size() < m*n && j>=sx)
            {
                res.push_back(matrix[i][j]);
                j--;
            }
            j++; i--; sx++;
            while (res.size() < m*n && i>sy)
            {
                res.push_back(matrix[i][j]);
                i--; 
            }
            i++; j++; sy++;
        }
        return res;
    }
};
 {% endhighlight %}