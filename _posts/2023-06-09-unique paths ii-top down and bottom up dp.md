---
layout: mypost
title: "Unique Paths II - Top down and bottom up DP"
tags: ["Array", "Dynamic Programming", "Matrix", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given an <code>m x n</code> integer array <code>grid</code>. There is a robot initially located at the <b>top-left corner</b> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>

<p>An obstacle and space are marked as <code>1</code> or <code>0</code> respectively in <code>grid</code>. A path that the robot takes cannot include <strong>any</strong> square that is an obstacle.</p>

<p>Return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>

<p>The testcases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right -&gt; Right
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;" />
<pre>
<strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == obstacleGrid.length</code></li>
	<li><code>n == obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
</ul>

# Solution:
The basic logic that we would like to implement is the following (in pseudocode):
 {% highlight cpp %} 
fun(i,j)
    if (i,j) is bottom-right corner return 1
    if i,j has obstacle return 0
    return fun(i+1,j) + fun(i,j+1) 
 {% endhighlight %}

Our final answer by this logic is `fun(0,0)`. We can implement this logic in top down or bottom up fashion.

*Top down solution*:
 {% highlight cpp %} 
class Solution {
    vector<vector<int>> memo;
public:
    int util(int i, int j, int m, int n, vector<vector<int>>&grid)
    {
        if (i==m-1 && j==n-1) return 1;
        if (i==m || j==n || grid[i][j]) return -1;
        if (memo[i][j]!=-1) return memo[i][j];
        int res = 0;
        int a = util(i+1, j, m, n, grid);
        int b = util(i, j+1, m, n, grid);
        if (a!=-1) res += a;
        if (b!=-1) res += b;
        return memo[i][j] = res;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        memo = vector<vector<int>>(m, vector<int>(n,-1));
        return util(0,0,m,n,obstacleGrid);
    }
};
 {% endhighlight %}

*Bottom-up solution*:
 {% highlight cpp %} 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<vector<int>> res(m, vector<int>(n,0));
        int r=0,c=0;
        while(r<m && obstacleGrid[r][0]==0) {res[r][0]=1; r++;}
        while(c<n && obstacleGrid[0][c]==0) {res[0][c]=1; c++;}
        for(int i=r; i<m; i++) res[i][0]=0;
        for(int j=c; j<n; j++) res[0][j]=0;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if (obstacleGrid[i][j]){res[i][j]=0; continue;}
                res[i][j] = res[i-1][j]+res[i][j-1];
            }
        }
        return res[m-1][n-1];        
    }
};
 {% endhighlight %}

*Bottom-up solution with $O(1)$ memory*:
 {% highlight cpp %} 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        if (grid[0][0] || grid[m-1][n-1]) return 0;
        int r=0,c=1;
        while(r<m && grid[r][0]==0) {grid[r][0]=1; r++;}
        while(c<n && grid[0][c]==0) {grid[0][c]=1; c++;}
        for(int i=r; i<m; i++) grid[i][0]=0;
        for(int j=c; j<n; j++) grid[0][j]=0;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if (grid[i][j]){grid[i][j]=0; continue;}
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[m-1][n-1];        
    }
};
 {% endhighlight %}

TC: $O(mn)$ for all solutions.