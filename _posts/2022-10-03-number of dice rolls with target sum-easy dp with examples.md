---
layout: mypost
title: "Number of Dice Rolls With Target Sum - Easy DP with examples"
tags: ["Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>You have <code>n</code> dice, and each die has <code>k</code> faces numbered from <code>1</code> to <code>k</code>.</p>

<p>Given three integers <code>n</code>, <code>k</code>, and <code>target</code>, return <em>the number of possible ways (out of the </em><code>k<sup>n</sup></code><em> total ways) </em><em>to roll the dice, so the sum of the face-up numbers equals </em><code>target</code>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 6, target = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> You throw one die with 6 faces.
There is only one way to get a sum of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, k = 6, target = 7
<strong>Output:</strong> 6
<strong>Explanation:</strong> You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 30, k = 30, target = 500
<strong>Output:</strong> 222616187
<strong>Explanation:</strong> The answer must be returned modulo 10<sup>9</sup> + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 30</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

# Solution:
Once you ponder over the question, it is easy to find the recurrence relation:
Consider k (# faces of each die) to be constant. Then, 
 {% highlight cpp %} 
rolls(n,target) = rolls(n-1,target-1) + rolls(n-1, target-2) + rolls(n-1, target-3) + ... + rolls(n-1,target-k)
 {% endhighlight %}

If you don't understand the above equation, consider that first item in the RHS corresponds to the case when last die has value 1 (and so the remaining n-1 dice must sum to target-1), second item corresponds to last die having value 2 (and so the remaining n-1 dice must sum to target-2) and so on such that last item corresponds to last die having value k (and so the remaining n-1 dice must sum to target-k). 

We will create a DP table bottom up. Size of table will be `(n+1, target+1)`. Top row and leftmost column will be zero except `dp[0][0] = 1`.  `dp[i,j]` denotes `rolls(i,j)`

Example of DP table for `numRollsToTarget(1,6,3)`:

| |T=0|T=1|T=2|T=3|
|--|---|---|---|---|
| N=0 | 1 | 0 | 0 | 0 |
| N=1 | 0 | 1 | 1 | 1 |


Example of DP table for `numRollsToTarget(2,6,7)`:

| |T=0|T=1|T=2|T=3|T=4|T=5|T=6|T=7
|--|---|---|---|---|---|---|---|---|
| N=0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| N=1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
| N=2 | 0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 

This gives us the following code:
 {% highlight cpp %} 
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // dp[i,j] denotes numRollsToTarget(i,k,j)
        dp[0][0] = 1;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=target; j++)
            {
                int temp = 0;
                for (int p=1; p<=min(k,j); p++) 
                    temp += dp[i-1][j-p];
                dp[i][j] = temp;
            }
        }
        return dp[n][target];
    }
};
 {% endhighlight %}

The above code is completely correct and will work (for small input). However we need to also handle large input and do the modulo thing. Hence here is the modified version.

 {% highlight cpp %} 
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // dp[i,j] denotes numRollsToTarget(i,k,j)
        dp[0][0] = 1;
        int mod = 1000000007;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=target; j++)
            {
                int temp = 0;
                for (int p=1; p<=min(k,j); p++) 
                {
                    temp = (temp%mod) + ( dp[i-1][j-p]%mod);
                    temp %= mod;
                }
                dp[i][j] = temp;
            }
        }
        return dp[n][target];
    }
};
 {% endhighlight %}