---
layout: mypost
title: "Increment Submatrices by One - Cumulative Sum"
tags: ["Array", "Matrix", "Prefix Sum", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a positive integer <code>n</code>, indicating that we initially have an <code>n x n</code>&nbsp;<strong>0-indexed</strong> integer matrix <code>mat</code> filled with zeroes.</p>

<p>You are also given a 2D integer array <code>query</code>. For each <code>query[i] = [row1<sub>i</sub>, col1<sub>i</sub>, row2<sub>i</sub>, col2<sub>i</sub>]</code>, you should do the following operation:</p>

<ul>
	<li>Add <code>1</code> to <strong>every element</strong> in the submatrix with the <strong>top left</strong> corner <code>(row1<sub>i</sub>, col1<sub>i</sub>)</code> and the <strong>bottom right</strong> corner <code>(row2<sub>i</sub>, col2<sub>i</sub>)</code>. That is, add <code>1</code> to <code>mat[x][y]</code> for all <code>row1<sub>i</sub> &lt;= x &lt;= row2<sub>i</sub></code> and <code>col1<sub>i</sub> &lt;= y &lt;= col2<sub>i</sub></code>.</li>
</ul>

<p>Return<em> the matrix</em> <code>mat</code><em> after performing every query.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/11/24/p2example11.png" style="width: 531px; height: 121px;" />
<pre>
<strong>Input:</strong> n = 3, queries = [[1,1,2,2],[0,0,1,1]]
<strong>Output:</strong> [[1,1,0],[1,2,1],[0,1,1]]
<strong>Explanation:</strong> The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
- In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
- In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/11/24/p2example22.png" style="width: 261px; height: 82px;" />
<pre>
<strong>Input:</strong> n = 2, queries = [[0,0,1,1]]
<strong>Output:</strong> [[1,1],[1,1]]
<strong>Explanation:</strong> The diagram above shows the initial matrix and the matrix after the first query.
- In the first query we add 1 to every element in the matrix.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= row1<sub>i</sub> &lt;= row2<sub>i</sub> &lt; n</code></li>
	<li><code>0 &lt;= col1<sub>i</sub> &lt;= col2<sub>i</sub> &lt; n</code></li>
</ul>

# Solution:
# Intuition
We will maintain a matrix where each update is `O(1)` in time. At the end, we will use cumulative sum method to get final output.

# Approach
Let us first solve the [1-D version of the problem](https://leetcode.com/problems/range-addition/). Also availabe [here](https://leetcode.ca/all/370.html). I will give a brief overview.
Problem is given length of array N starting with all zeros and some update queries of format `(left,right,increment)`, return the final array.
 {% highlight cpp %} 
Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
 {% endhighlight %}
A naive way would be to update from left to right for each query:
 {% highlight cpp %} 
vector<int> solve(int n, vector<vector<int>> updates)
{
    vector<int> A(n,0);
    for (auto &query: updates)
    {
        int left = query[0], right = query[1], increment = query[2];
        for (int i=left; i<=right; i++) A[i]+=increment;
    }
    return A;
}
 {% endhighlight %}
Here is a smarter way to do this: we just do `+increment` at `left` and `-increment` at `right+1` and finally return the cumulative sum array. We will need array of length `N+1` this time.
 {% highlight cpp %} 
vector<int> solve(int n, vector<vector<int>> updates)
{
    vector<int> A(n+1,0);
    for (auto &query: updates)
    {
        int left = query[0], right = query[1], increment = query[2];
        A[left]+=increment;
        A[right+1]-=increment
    }
    for (int i=1; i<=n; i++) A[i]+=A[i-1];
    A.pop_back(); // we want only first n items. A[n] is always zero
    return A;
}
 {% endhighlight %}
You can see that the first method is $O(Q*N)$ and second method is $O(Q+N)$ where `N` is size of array and `Q` is number of update queries.

Let us extend this logic to our problem.
Here we will do the following updates for each update query. 
 {% highlight cpp %} 
M[r1][c1]++;
M[r2+1][c1]--;
M[r1][c2+1]--;
M[r2+1][c2+1]++;
 {% endhighlight %}
The reason we need to do like this is because here we will be taking a 2-D cumulative sum by which we mean $res[i][j] = \sum_{ii,jj} M[ii][jj]$ where $0<=ii<=i$ and $0<=jj<=j$


# Complexity
- Time complexity: $O(Q + N^2)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(N^2)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
 {% highlight cpp %} 
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> M = vector<vector<int>>(n+1, vector<int>(n+1,0));
        for (auto &q: queries)
        {
            int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            M[r1][c1]++;
            M[r2+1][c1]--;
            M[r1][c2+1]--;
            M[r2+1][c2+1]++;
        }
        // Use this to print update matrix. You can check manually that the 2-D cumulative sum of this gives the answer
        // for (auto &v: M){for(int k: v)cout<<k<<',';cout<<endl;} 
        vector<vector<int>> res = vector<vector<int>>(n, vector<int>(n,0));
        res[0][0] = M[0][0];
        for (int i=1; i<n; i++) res[i][0]=res[i-1][0]+M[i][0];
        for (int j=1; j<n; j++) res[0][j]=res[0][j-1]+M[0][j];
        for (int i=1; i<n; i++) for (int j=1; j<n; j++)
            res[i][j] = -res[i-1][j-1]+res[i][j-1]+res[i-1][j]+M[i][j];
        return res;
    }
};
 {% endhighlight %}