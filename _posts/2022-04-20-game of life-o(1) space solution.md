---
layout: mypost
title: "Game of Life - O(1) space solution"
tags: ["Array", "Matrix", "Simulation", "Medium"]
---
# Problem Statement:
<p>According to&nbsp;<a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life" target="_blank">Wikipedia&#39;s article</a>: &quot;The <b>Game of Life</b>, also known simply as <b>Life</b>, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.&quot;</p>

<p>The board is made up of an <code>m x n</code> grid of cells, where each cell has an initial state: <b>live</b> (represented by a <code>1</code>) or <b>dead</b> (represented by a <code>0</code>). Each cell interacts with its <a href="https://en.wikipedia.org/wiki/Moore_neighborhood" target="_blank">eight neighbors</a> (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):</p>

<ol>
	<li>Any live cell with fewer than two live neighbors dies as if caused by under-population.</li>
	<li>Any live cell with two or three live neighbors lives on to the next generation.</li>
	<li>Any live cell with more than three live neighbors dies, as if by over-population.</li>
	<li>Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.</li>
</ol>

<p><span>The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the <code>m x n</code> grid <code>board</code>, return <em>the next state</em>.</span></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg" style="width: 562px; height: 322px;" />
<pre>
<strong>Input:</strong> board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
<strong>Output:</strong> [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg" style="width: 402px; height: 162px;" />
<pre>
<strong>Input:</strong> board = [[1,1],[1,0]]
<strong>Output:</strong> [[1,1],[1,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 25</code></li>
	<li><code>board[i][j]</code> is <code>0</code> or <code>1</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.</li>
	<li>In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?</li>
</ul>

# Solution:
**TC of both solutions is O(M\*N)**
# O(1) Space solution
Use 2 bits to maintain board. Left bit to store new values and right bit for original values.
```
class Solution {
public:
    int getNumNeighbors(vector<vector<int>>board,int m,int n, int i, int j)
    {
        int ctr=0;
        for (int x=max(i-1,0);x<min(i+2,m);x++)
            for (int y=max(j-1,0);y<min(j+2,n);y++) ctr+=board[x][y]&1;
        ctr-=board[i][j]&1;
        return ctr;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int num_neighbors=getNumNeighbors(board,m,n,i,j);
                if (board[i][j]==1 && num_neighbors<2) board[i][j]=1;
                if (board[i][j]==1 && num_neighbors>3) board[i][j]=1;
                if (board[i][j]==0 && num_neighbors==3)board[i][j]=2;
                if (board[i][j]==1 && (num_neighbors==2 || num_neighbors==3))board[i][j]=3;
            }
        }
        for (int i=0;i<m;i++) for (int j=0;j<n;j++) board[i][j]>>=1;
    }
};
```

# O(M\*N) space solution
Use auxiliary board variable to store new board values. Finally replace original with auxiliary.
```
class Solution {
public:
    int getNumNeighbors(vector<vector<int>>board,int m,int n, int i, int j)
    {
        int ctr=0;
        for (int x=max(i-1,0);x<min(i+2,m);x++)
            for (int y=max(j-1,0);y<min(j+2,n);y++) ctr+=board[x][y];
        ctr-=board[i][j];
        return ctr;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>> board_c(m,vector<int>(n,0));
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int num_neighbors=getNumNeighbors(board,m,n,i,j);
                if (board[i][j]==1 && num_neighbors<2) board_c[i][j]=0;
                if (board[i][j]==1 && num_neighbors>3) board_c[i][j]=0;
                if (board[i][j]==0 && num_neighbors==3)board_c[i][j]=1;
                if (board[i][j]==1 && (num_neighbors==2 || num_neighbors==3))board_c[i][j]=1;
            }
        }
        board = board_c;
    }
};
```