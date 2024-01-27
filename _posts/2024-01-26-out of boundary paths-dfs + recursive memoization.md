---
layout: mypost
title: "Out of Boundary Paths - DFS + Recursive Memoization"
tags: ["Dynamic Programming", "C++", "Depth-First Search", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>There is an <code>m x n</code> grid with a ball. The ball is initially at the position <code>[startRow, startColumn]</code>. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply <strong>at most</strong> <code>maxMove</code> moves to the ball.</p>

<p>Given the five integers <code>m</code>, <code>n</code>, <code>maxMove</code>, <code>startRow</code>, <code>startColumn</code>, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png" style="width: 500px; height: 296px;" />
<pre>
<strong>Input:</strong> m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png" style="width: 500px; height: 293px;" />
<pre>
<strong>Input:</strong> m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= maxMove &lt;= 50</code></li>
	<li><code>0 &lt;= startRow &lt; m</code></li>
	<li><code>0 &lt;= startColumn &lt; n</code></li>
</ul>

# Solution:
For edge and corner cells, the number of paths is the following:
 {% highlight cpp %} 
 (startRow==0) + (startRow==m-1) + (startColumn==0) + (startColumn==n-1);
 {% endhighlight %}
Now, starting from a location, we have to sum `fndPaths` for each neighbor and return the answer. We use DFS for this and we add memoization to make sure we are avoiding repeated calculation.


 {% highlight cpp %} 
class Solution {
    int mod = 1e9+7;
    vector<vector<int>> memo  = vector<vector<int>>(3000,vector<int>(60,-1));
    vector<pair<int,int>> moves = vector<pair<int,int>>{ {-1,0},{+1,0},{0,-1},{0,+1} };
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        if(maxMove<=0||startRow<0||startColumn<0||startRow>=m||startColumn>=n) return 0;
        int pos = startRow*n + startColumn;
        if (memo[pos][maxMove] >= 0) return memo[pos][maxMove];
        int x = (startRow==0) + (startRow==m-1) + (startColumn==0) + (startColumn==n-1);
        for (auto &move: moves)
        {
            x += findPaths(m,n,maxMove-1,startRow+move.first,startColumn+move.second);
            x %= mod;
        }
        return memo[pos][maxMove] = x;
    }
};
 {% endhighlight %}

 {% highlight cpp %} 
TC: O(m * n * N)
SC: O(m * n * N)
 {% endhighlight %}