---
layout: mypost
title: "Surrounded Regions - Island method [DFS]"
tags: ["Array", "Depth-First Search", "Breadth-First Search", "Union Find", "Matrix", "Medium"]
---
# Problem Statement:
<p>Given an <code>m x n</code> matrix <code>board</code> containing <code>&#39;X&#39;</code> and <code>&#39;O&#39;</code>, <em>capture all regions that are 4-directionally&nbsp;surrounded by</em> <code>&#39;X&#39;</code>.</p>

<p>A region is <strong>captured</strong> by flipping all <code>&#39;O&#39;</code>s into <code>&#39;X&#39;</code>s in that surrounded region.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" style="width: 550px; height: 237px;" />
<pre>
<strong>Input:</strong> board = [[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;O&quot;,&quot;O&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;X&quot;,&quot;O&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;O&quot;,&quot;X&quot;,&quot;X&quot;]]
<strong>Output:</strong> [[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;O&quot;,&quot;X&quot;,&quot;X&quot;]]
<strong>Explanation:</strong> Notice that an &#39;O&#39; should not be flipped if:
- It is on the border, or
- It is adjacent to an &#39;O&#39; that should not be flipped.
The bottom &#39;O&#39; is on the border, so it is not flipped.
The other three &#39;O&#39; form a surrounded region, so they are flipped.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> board = [[&quot;X&quot;]]
<strong>Output:</strong> [[&quot;X&quot;]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> is <code>&#39;X&#39;</code> or <code>&#39;O&#39;</code>.</li>
</ul>

# Solution:
This is inspired from my previous posts on simlar questions: [Number of Islands](https://leetcode.com/problems/number-of-islands/discuss/2714931/Easy-DFS) and [Count sub islands](https://leetcode.com/problems/count-sub-islands/discuss/2632544/DFS-solution).

The idea is to collect all the cells of an island in an array and check if the island is indeed surrounded or not. If it is then we change to X's and if not, we revert to original. The check for whether an island is surrounded or not is pretty simple: If any of its cells is a boundary cell then it is not surrounded and if not then it is surrounded.

```
class Solution {
public:
    void dfs(vector<vector<char>> &board, int m, int n, int i, int j, vector<pair<int,int>>&isle)
    {
        if (i<0||i>=m||j<0||j>=n||board[i][j]!='O') return;
        board[i][j] = '*';
        isle.push_back({i,j});
        dfs(board,m,n,i-1,j,isle);
        dfs(board,m,n,i+1,j,isle);
        dfs(board,m,n,i,j-1,isle);
        dfs(board,m,n,i,j+1,isle);
    }
    void surround(vector<vector<char>> &board, int m, int n,vector<pair<int,int>>&isle)
    {
        bool toSurround = true;
        for (auto p: isle)
            if (p.first==0 || p.first==(m-1) || p.second==0 || p.second==n-1)
            {
                toSurround = false;
                break;
            }
        if (toSurround)
        {
            for (auto p: isle)
                board[p.first][p.second] = 'X';            
        }
        else
        {
            for (auto p: isle)
                board[p.first][p.second] = 'O';            
        }
        
    }
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n=board[0].size();
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (board[i][j]=='O')
                {
                    vector<pair<int,int>> isle;
                    dfs(board,m,n,i,j,isle);
                    surround(board,m,n,isle);
                }
            }
        }
    }
};
```

The other method is to mark all islands having at leat one cell at boundary with `*`. Then if you find land, depending on whether it is marked or not convert it to 'X' or back to 'O'.
```
class Solution {
public:
    void dfs(vector<vector<char>>& board, int m, int n, int i, int j)
    {
        if (i<0||i>=m||j<0||j>=n||board[i][j]!='O') return;
        board[i][j] = '*';
        dfs(board,m,n,i-1,j);
        dfs(board,m,n,i+1,j);
        dfs(board,m,n,i,j-1);
        dfs(board,m,n,i,j+1);
    }
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n=board[0].size();
        for (int i=0; i<m; ++i)
        {
            dfs(board, m, n, i, 0);
            dfs(board, m, n, i, n-1);
        }
        for (int j=0; j<n; ++j)
        {
            dfs(board, m, n, 0, j);
            dfs(board, m, n, m-1, j);
        }
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (board[i][j]=='*')
                    board[i][j] = 'O';
                else if (board[i][j] = 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
};
```
Credits for 2nd method goes to [this post](https://leetcode.com/problems/surrounded-regions/discuss/691675/C%2B%2B-Beginner-Friendly-or-Boundary-DFS-or-inPlace)

# Note on TC and SC
Both the solutions have `O(m*n)` TC and first solution has `O(m*n)` SC whereas second solution has `O(1)` SC.

In general for any grid type problem it is impossible to find better than `O(m*n)` TC but the SC can be improved as we saw here.