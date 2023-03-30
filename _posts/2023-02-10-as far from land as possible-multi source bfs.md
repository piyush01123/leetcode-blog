---
layout: mypost
title: "As Far from Land as Possible - Multi Source BFS"
tags: ["Array", "Dynamic Programming", "Breadth-First Search", "Matrix", "C++", "Medium"]
---
# Problem Statement:
<p>Given an <code>n x n</code> <code>grid</code>&nbsp;containing only values <code>0</code> and <code>1</code>, where&nbsp;<code>0</code> represents water&nbsp;and <code>1</code> represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance.&nbsp;If no land or water exists in the grid, return <code>-1</code>.</p>

<p>The distance used in this problem is the Manhattan distance:&nbsp;the distance between two cells <code>(x0, y0)</code> and <code>(x1, y1)</code> is <code>|x0 - x1| + |y0 - y1|</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG" style="width: 185px; height: 87px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,1],[0,0,0],[1,0,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The cell (1, 1) is as far as possible from all the land with distance 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG" style="width: 184px; height: 87px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,0],[0,0,0],[0,0,0]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The cell (2, 2) is as far as possible from all the land with distance 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>grid[i][j]</code>&nbsp;is <code>0</code> or <code>1</code></li>
</ul>

# Solution:
BFS is very appropriate here. We just need to check how many times we need to traverse to finish the queue of land cells. In one traversal, all adjacent members of the current queue get covered and converted to land cells. 

 {% highlight cpp %} 
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size(), distance=-1;
        queue<pair<int,int>> Q;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++)
            if (grid[i][j]) Q.push({i,j});
        if (Q.empty()||Q.size()==n*n) return -1;//All water or all land
        vector<pair<int,int>> directions{ {-1,0},{1,0},{0,-1},{0,1} };
        while (!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                auto cell = Q.front();
                Q.pop();
                for (auto &dir: directions)
                {
                    int x = cell.first+dir.first;
                    int y = cell.second+dir.second;
                    if (x<0||x>=n||y<0||y>=n) continue;
                    if (grid[x][y]==0)
                    {
                        grid[x][y] = 1;
                        Q.push({x,y});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};
 {% endhighlight %}