---
layout: mypost
title: "Maximum Value of K Coins From Piles - Bottom-up DP explained"
tags: ["Array", "Dynamic Programming", "Prefix Sum", "C++", "Hard"]
---
# Problem Statement:
<p>There are <code>n</code> <strong>piles</strong> of coins on a table. Each pile consists of a <strong>positive number</strong> of coins of assorted denominations.</p>

<p>In one move, you can choose any coin on <strong>top</strong> of any pile, remove it, and add it to your wallet.</p>

<p>Given a list <code>piles</code>, where <code>piles[i]</code> is a list of integers denoting the composition of the <code>i<sup>th</sup></code> pile from <strong>top to bottom</strong>, and a positive integer <code>k</code>, return <em>the <strong>maximum total value</strong> of coins you can have in your wallet if you choose <strong>exactly</strong></em> <code>k</code> <em>coins optimally</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/09/e1.png" style="width: 600px; height: 243px;" />
<pre>
<strong>Input:</strong> piles = [[1,100,3],[7,8,9]], k = 2
<strong>Output:</strong> 101
<strong>Explanation:</strong>
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
<strong>Output:</strong> 706
<strong>Explanation:
</strong>The maximum total can be obtained if we choose all coins from the last pile.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == piles.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= piles[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= sum(piles[i].length) &lt;= 2000</code></li>
</ul>

# Solution:
We define `dp[i][j]` as the the answer considering 1st `i` piles for at most `j` coins. Hence final answer is `dp[n][k]`. In base case we consider `i=0` ie considering zero piles. This row will be just zeroes. Similarly for `j=0` column also, it will be all zeroes. 

Consider any general `dp[i][j]`. 

We can take 0 coins from `i`th pile and all the `j` coins from the first `i-1` piles. The value for this situation is `dp[i-1][j] + 0`.

We can also take 3 coins from `ith pile` (assume valid) and `j-3` coins from the first `i-1` piles. The value for this situation is `dp[i-1][j-3] + piles[i-1][0]+piles[i-1][1]+piles[i-1][2]`. 

Similarly we can have other possiblities as well. `dp[i][j]` is the maximum of all these possibilities.

We define `cur` as the number of coins we take from the current pile and `curSum` as the sum of values of these `cur` coins.


 {% highlight cpp %} 
int maxValueOfCoins(vector<vector<int>>& piles, int k) 
{
    int n = piles.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=k; j++)
        {
            dp[i][j] = dp[i-1][j]; // cur=0
            int curSum = 0;
            for (int cur=1; cur<=min((int)piles[i-1].size(),j); cur++)
            {
                curSum += piles[i-1][cur-1];
                dp[i][j] = max(dp[i][j], dp[i-1][j-cur]+curSum);
            }
        }
    }
    return dp[n][k];
}
 {% endhighlight %}

$$TC= O(n\sum_{i=1}^n {P_i})$$ where $P_i$ is the size of ith pile.
$$SC: O(nk)$$