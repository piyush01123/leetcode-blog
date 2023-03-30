---
layout: mypost
title: "Minimum Path Sum - Easy O(m*n)"
tags: ["Array", "Dynamic Programming", "Matrix", "C++", "Medium"]
---
# Problem Statement:
<p>Given a <code>m x n</code> <code>grid</code> filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>

<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 &rarr; 3 &rarr; 1 &rarr; 1 &rarr; 1 minimizes the sum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

# Solution:
The top row and leftmost column can simply be computed.
After that for any node, the answer can be either its upward neighbor + node value or its leftward neighbor + node value;
 {% highlight cpp %} 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> sumgrid(m, vector<int>(n,0));
        sumgrid[0][0] = grid[0][0];
        for (int i=1; i<m; i++) 
            sumgrid[i][0] = sumgrid[i-1][0] + grid[i][0];
        for (int j=1; j<n; j++)
            sumgrid[0][j] = sumgrid[0][j-1] + grid[0][j];
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                sumgrid[i][j] = min(sumgrid[i-1][j],sumgrid[i][j-1]) + grid[i][j];
        return sumgrid[m-1][n-1];
    }
};
 {% endhighlight %}