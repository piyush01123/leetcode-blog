---
layout: mypost
title: "Longest Palindromic Subsequence - Bottom-up DP explained"
tags: ["String", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>Given a string <code>s</code>, find <em>the longest palindromic <strong>subsequence</strong>&#39;s length in</em> <code>s</code>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bbbab&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible longest palindromic subsequence is &quot;bbbb&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbbd&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> One possible longest palindromic subsequence is &quot;bb&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>

# Solution:
## Approach
We denote `dp[i][j]` as the answer for the string `s[i...j]`. Hence final answer is `dp[0][n-1]` where `n` is length of string `s`.

Now, to get `dp[i][j]`, we firstly start with the base case that is if `i==j` or `i==j+1`. Both of these are trivial to calculate. For other cases, we have three possiilities. Multiple of these can be true at a a time but the answer will still hold true.

- The subsequence lies in `s[i+1..j]`
- The subsequence lies in `s[i..j-1]`
- `s[i]` and `s[j]` are part of the subsequence

We take a maximum of all these cases as the answer.

## Code
 {% highlight cpp %} 
int longestPalindromeSubseq(string s) 
{
    int n = s.length();
    vector<vector<int>> dp (n, vector<int>(n, -1));
    for (int len=1; len<=n; len++)
    {
        for (int i=0; i+len-1<n; i++)
        {
            int j = i+len-1;
            if (len==1) dp[i][j] = 1;
            else if (len==2) dp[i][j] = ((s[i]==s[j]) ? 2 : 1);
            else
            {
                int a = dp[i+1][j-1] + ((s[i]==s[j])?2:0);
                int b = dp[i+1][j];
                int c = dp[i][j-1];
                dp[i][j] = max(max(a,b),c);
            }
        }
    }
    return dp[0][n-1];
}
 {% endhighlight %}
## Analysis:

TC: $O(n^2)$
SC: $O(n^2)$