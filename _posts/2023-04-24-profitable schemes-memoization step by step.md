---
layout: mypost
title: "Profitable Schemes - Memoization step by step"
tags: ["Array", "Dynamic Programming", "C++", "Depth-First Search", "Memoization", "Hard"]
---
# Problem Statement:
<p>There is a group of <code>n</code> members, and a list of various crimes they could commit. The <code>i<sup>th</sup></code> crime generates a <code>profit[i]</code> and requires <code>group[i]</code> members to participate in it. If a member participates in one crime, that member can&#39;t participate in another crime.</p>

<p>Let&#39;s call a <strong>profitable scheme</strong> any subset of these crimes that generates at least <code>minProfit</code> profit, and the total number of members participating in that subset of crimes is at most <code>n</code>.</p>

<p>Return the number of schemes that can be chosen. Since the answer may be very large, <strong>return it modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5, minProfit = 3, group = [2,2], profit = [2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
<strong>Output:</strong> 7
<strong>Explanation:</strong> To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= minProfit &lt;= 100</code></li>
	<li><code>1 &lt;= group.length &lt;= 100</code></li>
	<li><code>1 &lt;= group[i] &lt;= 100</code></li>
	<li><code>profit.length == group.length</code></li>
	<li><code>0 &lt;= profit[i] &lt;= 100</code></li>
</ul>

# Solution:
For each crime, we can take it or not take it in the scheme. So there are $2^m$ unique schemes possible, where $m$ is the number of crimes. If we do take it, we are left with $n-G[i]$ people, where `G[i]` is the size of group needed for ith crime and the profit becomes $p+P[i]$. If we do not take it, we have $n$ people and $p$ profit. We can have a recursive solution like this.
 {% highlight cpp %} 
int profitableSchemes(int n, int minProfit, vector<int>& groups, vector<int>& profits, int i=0, int p=0) 
{
    if (i==groups.size()) return (p>=minProfit)?1:0;
    int cur = 0;
    cur += profitableSchemes(n, minProfit, groups, profits, i+1, p);
    if (n-groups[i]>=0)
        cur += profitableSchemes(n-groups[i], minProfit, groups, profits, i+1, p+profits[i]);
    return cur;
}
 {% endhighlight %}
We can write the same solution in a different way in order to memoise it later.
 {% highlight cpp %} 
int dfs(int i, int n, int p, vector<int>&groups, vector<int>&profits, int minProfit)
{
    if (i==groups.size()) return (p>=minProfit)?1:0;
    int cur = 0;
    cur += dfs(i+1, n, p, groups, profits, minProfit);
    if (n-groups[i]>=0)
        cur += dfs(i+1, n-groups[i], p+profits[i], groups, profits, minProfit);
    return cur;
}
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
{
    return dfs(0, n, 0, group, profit, minProfit);
}
 {% endhighlight %}

We can add memoization to make it faster. Also add mod.

 {% highlight cpp %} 
int mod = 1e9+7;
int dfs(int i, int n, int p, vector<int>&groups, vector<int>&profits, int minProfit, vector<vector<vector<int>>>&dp)
{
    if (i==groups.size()) return (p>=minProfit)?1:0;
    if (dp[i][n][p]!=-1) return dp[i][n][p];
    int cur = 0;
    cur += dfs(i+1, n, p, groups, profits, minProfit, dp)   %mod;
    if (n-groups[i]>=0)
        cur += dfs(i+1, n-groups[i], min(minProfit, p+profits[i]), groups, profits, minProfit, dp)\
                %mod;
    return dp[i][n][p] = cur%mod;
}
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
{
    vector<vector<vector<int>>> dp(group.size()+1, vector<vector<int>>(n+1, \
                                                vector<int>(minProfit+1,-1)));
    return dfs(0, n, 0, group, profit, minProfit, dp);
}
 {% endhighlight %}

TC: $O(NMP)$, SC: $O(NMP)$ where $N$ is number of people, $M$ is the number of crimes, $P$ is `minProfit`.