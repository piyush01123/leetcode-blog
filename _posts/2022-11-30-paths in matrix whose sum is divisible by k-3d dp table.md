---
layout: mypost
title: "Paths in Matrix Whose Sum Is Divisible by K - 3D DP table"
tags: ["Array", "Dynamic Programming", "Matrix", "C++", "Hard"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> <code>m x n</code> integer matrix <code>grid</code> and an integer <code>k</code>. You are currently at position <code>(0, 0)</code> and you want to reach position <code>(m - 1, n - 1)</code> moving only <strong>down</strong> or <strong>right</strong>.</p>

<p>Return<em> the number of paths where the sum of the elements on the path is divisible by </em><code>k</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/13/image-20220813183124-1.png" style="width: 437px; height: 200px;" />
<pre>
<strong>Input:</strong> grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/17/image-20220817112930-3.png" style="height: 85px; width: 132px;" />
<pre>
<strong>Input:</strong> grid = [[0,0]], k = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/12/image-20220812224605-3.png" style="width: 257px; height: 200px;" />
<pre>
<strong>Input:</strong> grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>

# Solution:
Firstly a note regarding notation, I have replaced small k with capital K and I am using small k for indexing.
# Algorithm:
We will create a DP table of shape `(M,N,K)` where `dp[i][j][k]` denotes number of ways to reach `(i,j)` coordinate with `sum%K==k`. At the end we will return `dp[M-1][N-1][0]`.

Now for `(0,0)` there is one way to reach `dp[0][0]%K` but for other values of k, there is no way to achieve that sum.

## Recurrence relation
 {% highlight cpp %} 
dp[i][j][k] = A + B
 {% endhighlight %}

where A is the number of ways to reach `(i,j)` via `(i,j-1)` and B is the number of ways to reach `(i,j)` via `(i-1,j)`
Now we know that `A = dp[i][j-1][idx]`. We want to find this `idx`
Suppose `grid[i][j]%K==x`. Then 
 {% highlight cpp %} 
idx = (K + k - x) % K
 {% endhighlight %}
This `idx` value is same even for `(i-1,j)`

# C++ code:
 {% highlight cpp %} 
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) 
    {
        int m=grid.size(), n=grid[0].size(), mod=1000000007;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(K,0)));
        dp[0][0][grid[0][0]%K]++;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                for (int k=0; k<K; k++)
                {
                    if (i==0 && j==0) continue;
                    int a = ((j==0) ? 0 : dp[i][j-1][(K+k-grid[i][j]%K)%K] % mod);
                    int b = ((i==0) ? 0 : dp[i-1][j][(K+k-grid[i][j]%K)%K] % mod);
                    dp[i][j][k] = (a+b)%mod;
                }
        return dp[m-1][n-1][0];
    }
};
 {% endhighlight %}