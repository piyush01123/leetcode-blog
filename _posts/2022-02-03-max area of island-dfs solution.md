---
layout: mypost
title: "Max Area of Island - DFS solution"
tags: ["Array", "Depth-First Search", "Breadth-First Search", "Union Find", "Matrix", "Python", "C", "Medium"]
---
# Problem Statement:
<p>You are given an <code>m x n</code> binary matrix <code>grid</code>. An island is a group of <code>1</code>&#39;s (representing land) connected <strong>4-directionally</strong> (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.</p>

<p>The <strong>area</strong> of an island is the number of cells with a value <code>1</code> in the island.</p>

<p>Return <em>the maximum <strong>area</strong> of an island in </em><code>grid</code>. If there is no island, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg" style="width: 500px; height: 310px;" />
<pre>
<strong>Input:</strong> grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The answer is not 11, because the island must be connected 4-directionally.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0,0,0,0,0,0,0,0]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

# Solution:
 {% highlight python %} 
class Solution {
public:
    int util(int r, int c, vector<vector<int>> &grid, int m, int n, unordered_set<int> &visited)
    {
        if (r<0 || r>=m || c<0 || c>=n) return 0;
        if (visited.count(n*r+c)>0 || grid[r][c]==0) return 0;
        visited.insert(n*r+c);
        return 1 + util(r-1,c,grid,m,n,visited) + util(r+1,c,grid,m,n,visited) + \
                   util(r,c-1,grid,m,n,visited) + util(r,c+1,grid,m,n,visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        unordered_set<int> visited;
        for (int r=0; r<m; r++)
            for (int c=0; c<n; c++)
                res = max(res, util(r,c,grid,m,n,visited));
        return res;
    }
};
 {% endhighlight %}
 {% highlight python %} 
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        seen = set()
        def util(r,c):
            if r<0 or r>=m or c<0 or c>=n or (r,c) in seen or grid[r][c]==0:
                return 0
            seen.add((r,c))
            return 1+util(r+1,c)+util(r-1,c)+util(r,c+1)+util(r,c-1)
        return max([max([util(r,c) for c in range(n)]) for r in range(m)])
 {% endhighlight %}