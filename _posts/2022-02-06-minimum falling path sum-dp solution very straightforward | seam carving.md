---
layout: mypost
title: "Minimum Falling Path Sum - DP Solution very straightforward | Seam Carving"
tags: ["Array", "Dynamic Programming", "Matrix", "Python", "Medium"]
---
# Problem Statement:
<p>Given an <code>n x n</code> array of integers <code>matrix</code>, return <em>the <strong>minimum sum</strong> of any <strong>falling path</strong> through</em> <code>matrix</code>.</p>

<p>A <strong>falling path</strong> starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position <code>(row, col)</code> will be <code>(row + 1, col - 1)</code>, <code>(row + 1, col)</code>, or <code>(row + 1, col + 1)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg" style="width: 499px; height: 500px;" />
<pre>
<strong>Input:</strong> matrix = [[2,1,3],[6,5,4],[7,8,9]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> There are two falling paths with a minimum sum as shown.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg" style="width: 164px; height: 365px;" />
<pre>
<strong>Input:</strong> matrix = [[-19,57],[-40,-5]]
<strong>Output:</strong> -59
<strong>Explanation:</strong> The falling path with a minimum sum is shown.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>

# Solution:
- Create a `dp` matrix of size (nxn)
- Copy last row of `matrix` to last row of `dp`
- Iteratively go up from `r=n-2` to `r=0`. For element `(r,c)` the expression we have is: `dp[r,c] = min(dp[r+1,c-1], dp[r+1,c], dp[r+1,c+1])`
- For `c=0` and `c=n-1` take min of only two elements rather than 3. These are left and right edges
- After reaching top row, check which element in top row is the minimum.
- Done!


 {% highlight python %} 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int c=0; c<n; c++) dp[n-1][c] = matrix[n-1][c];
        for (int r=n-2; r>=0; r--)
        {
            for (int c=0; c<n; c++)
            {
                if (c==0) dp[r][c] = min(dp[r+1][c], dp[r+1][c+1]) + matrix[r][c];
                else if (c==n-1) dp[r][c] = min(dp[r+1][c], dp[r+1][c-1]) + matrix[r][c];
                else dp[r][c] = min(min(dp[r+1][c-1], dp[r+1][c]), dp[r+1][c+1]) + matrix[r][c];
            }
        }
        int res=INT_MAX;
        for (int c=0; c<n; c++) res = min(res, dp[0][c]);
        return res;
    }
};
 {% endhighlight %}

BTW, this algorithm is used in a smart image resizing method known as [Seam Carving](https://en.wikipedia.org/wiki/Seam_carving).