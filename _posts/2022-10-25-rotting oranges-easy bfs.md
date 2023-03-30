---
layout: mypost
title: "Rotting Oranges - Easy BFS"
tags: ["Array", "Breadth-First Search", "Matrix", "C++", "Medium"]
---
# Problem Statement:
<p>You are given an <code>m x n</code> <code>grid</code> where each cell can have one of three values:</p>

<ul>
	<li><code>0</code> representing an empty cell,</li>
	<li><code>1</code> representing a fresh orange, or</li>
	<li><code>2</code> representing a rotten orange.</li>
</ul>

<p>Every minute, any fresh orange that is <strong>4-directionally adjacent</strong> to a rotten orange becomes rotten.</p>

<p>Return <em>the minimum number of minutes that must elapse until no cell has a fresh orange</em>. If <em>this is impossible, return</em> <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/16/oranges.png" style="width: 650px; height: 137px;" />
<pre>
<strong>Input:</strong> grid = [[2,1,1],[1,1,0],[0,1,1]]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[2,1,1],[0,1,1],[1,0,1]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0,2]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since there are already no fresh oranges at minute 0, the answer is just 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>grid[i][j]</code> is <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

# Solution:
BFS is very appropriate here. We just need to check how many times we need to traverse to finish the queue. In one traversal, all adjacent members of the current queue get covered. At the end we also check thre is a fresh orange, if yes we return -1 and if not we return the answer.
- Add all cells with rotten oranges in Queue.
- Run BFS in the queue.
- Count the number of times we need to traverse.
- After we are done, check for any fresh remaining orange.

C++ Code:

 {% highlight cpp %} 
class Solution {
public:
    bool notdone(vector<vector<int>> &grid)
    {
        for (auto row: grid)
            for (int cell: row)
                if (cell==1)
                    return true;
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) 
    {
        if (!notdone(grid)) return 0;
        int m=grid.size(), n=grid[0].size(), ctr=0;
        vector<pair<int,int>> dirs { {-1,0},{1,0},{0,-1},{0,1} };
        queue<pair<int,int>> Q;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==2)
                    Q.push({i,j});
        while (!Q.empty())
        {
            int qsize = Q.size();
            for (int i=0; i<qsize; i++)
            {
                auto point = Q.front();
                Q.pop();
                for (auto dir: dirs)
                {
                    int x = point.first + dir.first;
                    int y = point.second + dir.second;
                    if (x<0 || x>=m || y<0 || y>=n || grid[x][y]!=1)
                        continue;
                    grid[x][y] = 2;
                    Q.push({x,y});
                }
            }
            ctr++;
        }
        if (notdone(grid)) return -1;
        return ctr-1;
    }
};
 {% endhighlight %}