---
layout: mypost
title: "Longest Palindromic Substring - Boolean DP"
tags: ["String", "Dynamic Programming", "C++", "Java", "Medium"]
---
# Problem Statement:
<p>Given a string <code>s</code>, return <em>the longest</em> <span data-keyword="palindromic-string"><em>palindromic</em></span> <span data-keyword="substring-nonempty"><em>substring</em></span> in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;babad&quot;
<strong>Output:</strong> &quot;bab&quot;
<strong>Explanation:</strong> &quot;aba&quot; is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbbd&quot;
<strong>Output:</strong> &quot;bb&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consist of only digits and English letters.</li>
</ul>

# Solution:
We build a boolean 2-D table `dp` of size n by n such that `dp[i][j]`stores whether or not the substring starting at `i` and ending at `j` is a palindrome.

We start with `len=1` and go upto `len=n`. Note that if the substring starts at index `i` and has length `len` then the substring will end at `j=i+len-1`. 

Generally we can say that `s(i,...,j)` is a palindrome if the substring `s(i+1,...,j-1)` is a palindrome and `s[i]==s[j]`. We  will have to handle cases of `len=1,2` separately. 

Java solution:
 {% highlight java %} 
class Solution 
{
    public String longestPalindrome(String s) 
    {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=false;
        String res="";
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i<=n-len; i++)
            {
                int j = i+len-1;
                dp[i][j] = s.charAt(i)==s.charAt(j) && ((len<=2) || dp[i+1][j-1]);
                if (dp[i][j]) res = s.substring(i,j+1);
            }
        }
        return res;        
    }
}
 {% endhighlight %}
C++ solution:
 {% highlight java %} 
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        string res;
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i<=n-len; i++)
            {
                int j = i+len-1;
                dp[i][j] = s[i]==s[j] && ((len<=2) || dp[i+1][j-1]);
                if (dp[i][j]) res = s.substr(i,len);
            }
        }
        return res;
    }
};
 {% endhighlight %}