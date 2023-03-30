---
layout: mypost
title: "Word Search - Help needed for DFS solution"
tags: ["Array", "Backtracking", "Matrix", "Medium"]
---
# Problem Statement:
<p>Given an <code>m x n</code> grid of characters <code>board</code> and a string <code>word</code>, return <code>true</code> <em>if</em> <code>word</code> <em>exists in the grid</em>.</p>

<p>The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> board = [[&quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;E&quot;],[&quot;S&quot;,&quot;F&quot;,&quot;C&quot;,&quot;S&quot;],[&quot;A&quot;,&quot;D&quot;,&quot;E&quot;,&quot;E&quot;]], word = &quot;ABCCED&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> board = [[&quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;E&quot;],[&quot;S&quot;,&quot;F&quot;,&quot;C&quot;,&quot;S&quot;],[&quot;A&quot;,&quot;D&quot;,&quot;E&quot;,&quot;E&quot;]], word = &quot;SEE&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> board = [[&quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;E&quot;],[&quot;S&quot;,&quot;F&quot;,&quot;C&quot;,&quot;S&quot;],[&quot;A&quot;,&quot;D&quot;,&quot;E&quot;,&quot;E&quot;]], word = &quot;ABCB&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n = board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 6</code></li>
	<li><code>1 &lt;= word.length &lt;= 15</code></li>
	<li><code>board</code> and <code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you use search pruning to make your solution faster with a larger <code>board</code>?</p>

# Solution:
Like others my solution also uses DFS but I am getting TLE. It uses more memory than other approaches (to store copies of intermediate strings `curr` and  boolean`visited` matrices) but can that lead to TLE?

```
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int m, int n, int i,  int j, string word, string curr, vector<vector<bool>> visited)
    {
        if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || board[i][j]!=word[curr.length()]) return false;
        visited[i][j] = true;
        curr.push_back(board[i][j]);
        if (word==curr) return true;
        return dfs(board,m,n,i-1,j,word,curr,visited) ||
               dfs(board,m,n,i+1,j,word,curr,visited) ||
               dfs(board,m,n,i,j-1,word,curr,visited) ||
               dfs(board,m,n,i,j+1,word,curr,visited);
    }

	bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (dfs(board, m, n, i, j, word, "", visited))
                    return true;
            }
        }
        return false;
    }
};
```

# EDIT:
Based on other answers I modified above code to a low memory solution and it gets AC:
```
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int m, int n, int i,  int j, string word, int index)
    {
        if (i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[index]) return false;
        board[i][j] = '*';
        if (index==word.length()-1) return true;
        bool res =  dfs(board,m,n,i-1,j,word,index+1) ||
                       dfs(board,m,n,i+1,j,word,index+1) ||
                       dfs(board,m,n,i,j-1,word,index+1) ||
                       dfs(board,m,n,i,j+1,word,index+1);
        board[i][j] = word[index];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (dfs(board, m, n, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
```

Now both of these have same TC (`O(m*n*|word|)`) but SC is lesser (`O(m*n*|word|)`  for the TLE solution vs `O(|word|)` for the AC solution. Can this lead to TLE? Shouldn't it be `Memory limited exceeded` or something if it takes too much memory space?