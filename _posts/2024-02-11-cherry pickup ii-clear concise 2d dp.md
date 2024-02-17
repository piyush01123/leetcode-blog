---
layout: mypost
title: "Cherry Pickup II - Clear concise 2D DP"
tags: ["Array", "Dynamic Programming", "Matrix", "C++", "Hard"]
---
# Problem Statement:
<p>You are given a <code>rows x cols</code> matrix <code>grid</code> representing a field of cherries where <code>grid[i][j]</code> represents the number of cherries that you can collect from the <code>(i, j)</code> cell.</p>

<p>You have two robots that can collect cherries for you:</p>

<ul>
	<li><strong>Robot #1</strong> is located at the <strong>top-left corner</strong> <code>(0, 0)</code>, and</li>
	<li><strong>Robot #2</strong> is located at the <strong>top-right corner</strong> <code>(0, cols - 1)</code>.</li>
</ul>

<p>Return <em>the maximum number of cherries collection using both robots by following the rules below</em>:</p>

<ul>
	<li>From a cell <code>(i, j)</code>, robots can move to cell <code>(i + 1, j - 1)</code>, <code>(i + 1, j)</code>, or <code>(i + 1, j + 1)</code>.</li>
	<li>When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.</li>
	<li>When both robots stay in the same cell, only one takes the cherries.</li>
	<li>Both robots cannot move outside of the grid at any moment.</li>
	<li>Both robots should reach the bottom row in <code>grid</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/29/sample_1_1802.png" style="width: 374px; height: 501px;" />
<pre>
<strong>Input:</strong> grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
<strong>Output:</strong> 24
<strong>Explanation:</strong> Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/sample_2_1802.png" style="width: 500px; height: 452px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
<strong>Output:</strong> 28
<strong>Explanation:</strong> Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rows == grid.length</code></li>
	<li><code>cols == grid[i].length</code></li>
	<li><code>2 &lt;= rows, cols &lt;= 70</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

# Solution:
I see many solutions using 3D DP but it is not necessary. We can simplify the logic to 2D by storing only result of one row.

At any point while traversing from bottom to top, let us store the answer in a 2-D DP table `A` of size `(cols,cols)`. `A[i][j]` denotes the position `i` for robot 1 and `j` for robot 2. 

Further let us only consider situations where robot 2 is not to the left of robot 1 ie we want `j >= i`.

 {% highlight cpp %} 
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> A(cols, vector<int>(cols));
        for(int i=0; i<cols; i++) for(int j=i; j<cols; j++)
            A[i][j] = grid[rows-1][i] + (i==j ? 0 : grid[rows-1][j]);
        for(int row=rows-2; row>=0; row--)
        {
            vector<vector<int>> temp(cols, vector<int>(cols));
            for(int i=0; i<cols; i++) for(int j=i; j<cols; j++)
            {
                int a = grid[row][i], b = grid[row][j];
                int cur = a + (i==j ? 0 : b);
                int nextRow = INT_MIN;
                for(int ii=max(i-1,0); ii<=min(i+1,cols-1); ii++)
                for(int jj=max(j-1,0); jj<=min(j+1,cols-1); jj++)
                    nextRow = max(nextRow, A[ii][jj]);
                temp[i][j] = nextRow + cur;
            }
            A = temp;
        }
        return A[0][cols-1];
    }
};
 {% endhighlight %}