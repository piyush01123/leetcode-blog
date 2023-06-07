---
layout: mypost
title: "Maximum Number of Moves in a Grid - DFS + BFS + DP solutions"
tags: ["Array", "Dynamic Programming", "Matrix", "C++", "Depth-First Search", "Breadth-First Search", "Graph", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> <code>m x n</code> matrix <code>grid</code> consisting of <strong>positive</strong> integers.</p>

<p>You can start at <strong>any</strong> cell in the first column of the matrix, and traverse the grid in the following way:</p>

<ul>
	<li>From a cell <code>(row, col)</code>, you can move to any of the cells: <code>(row - 1, col + 1)</code>, <code>(row, col + 1)</code> and <code>(row + 1, col + 1)</code> such that the value of the cell you move to, should be <strong>strictly</strong> bigger than the value of the current cell.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of <strong>moves</strong> that you can perform.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/yetgriddrawio-10.png" style="width: 201px; height: 201px;" />
<pre>
<strong>Input:</strong> grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can start at the cell (0, 0) and make the following moves:
- (0, 0) -&gt; (0, 1).
- (0, 1) -&gt; (1, 2).
- (1, 2) -&gt; (2, 3).
It can be shown that it is the maximum number of moves that can be made.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/12/yetgrid4drawio.png" />
<strong>Input:</strong> grid = [[3,2,4],[2,1,9],[1,1,7]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Starting from any cell in the first column we cannot perform any moves.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>

# Solution:
**DFS**:
 {% highlight cpp %} 
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&visited, int m, int n)
    {
        if (j==n-1) return 0;
        int res=0;
        visited[i][j] = true;
        for (int ii=max(i-1,0); ii<=min(m-1,i+1); ii++)
            if (grid[ii][j+1]>grid[i][j] && !visited[ii][j+1])
                res = max(res, 1+dfs(ii,j+1,grid,visited,m,n));
        return res;
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for (int i=0; i<m; i++)
        {
            res = max(res, dfs(i, 0, grid, visited, m, n));
            if (res==n-1) return res;
        }
        return res;
    }
};
 {% endhighlight %}


**BFS**:
 {% highlight cpp %} 
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        queue<pair<int,int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++) 
        {
            Q.push({i,0});
            visited[i][0] = true;
        }
        while(!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                int curY=Q.front().first, curX=Q.front().second;
                if (curX==n-1) return n-1;
                Q.pop();
                for (int nbdY=max(0,curY-1); nbdY<=min(m-1,curY+1); nbdY++)
                {
                    int nbdX = curX+1;
                    if (grid[nbdY][nbdX]>grid[curY][curX] && !visited[nbdY][nbdX]) 
                    {
                        visited[nbdY][nbdX] = true;
                        Q.push({nbdY,nbdX});
                    }

                }
            }
            res++;
        }
        return res-1;
    }
};
 {% endhighlight %}


**DFS with DP**
 {% highlight cpp %} 
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid, int m, int n, vector<vector<int>>&A)
    {
        if (A[i][j]!=-1) return A[i][j];
        if (j==n-1) return 0;
        int a = (i>0 && grid[i-1][j+1]>grid[i][j]) ? 1+dfs(i-1,j+1,grid,m,n,A) : 0;
        int b = (grid[i][j+1]>grid[i][j]) ? 1+dfs(i,j+1,grid,m,n,A) : 0;
        int c = (i<m-1 && grid[i+1][j+1]>grid[i][j]) ? 1+dfs(i+1,j+1,grid,m,n,A) : 0;
        return A[i][j] = max({a,b,c});
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        vector<vector<int>> A(m, vector<int>(n,-1));
        for (int i=0; i<m; i++)
        {
            res = max(res, dfs(i,0,grid,m,n,A));
            if (res==n-1) return res;
        }
        return res;
    }
};
 {% endhighlight %}
