---
layout: mypost
title: "Palindromic Substrings - C++ DP with explanation"
tags: ["String", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>Given a string <code>s</code>, return <em>the number of <strong>palindromic substrings</strong> in it</em>.</p>

<p>A string is a <strong>palindrome</strong> when it reads the same backward as forward.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abc&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> Three palindromic strings: &quot;a&quot;, &quot;b&quot;, &quot;c&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaa&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> Six palindromic strings: &quot;a&quot;, &quot;a&quot;, &quot;a&quot;, &quot;aa&quot;, &quot;aa&quot;, &quot;aaa&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

# Solution:
Maintain a boolean 2D matrix table to store palindome-ity. Specifically `dp[i][j]` denotes `s[i,..,j]` is a palindrome or not (i and j included). 
The tricky part is that you have to traverse from Length = 1 to Length = n. For each length explore all possible starting positions for `i` and j then becomes `i+len-1`
The recurrence relation for palindrome-ity is
 {% highlight cpp %} 
dp[i][j] =  (s[i]==s[j] && dp[i+1][j-1])
 {% endhighlight %}
Basically it says if the outer two characters are same and the inside string is a palindrome then as a whole is a palindrome.
However, there is no inner string for strings of length 1 and 2. Hence we have to modify:
 {% highlight cpp %} 
dp[i][j] =  (s[i]==s[j] && (len<=2 || dp[i+1][j-1]))
 {% endhighlight %}

C++ code:
 {% highlight cpp %} 
class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length(), ctr = 0;
        vector<vector<bool>> dp(n, vector(n,false));
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i<=n-len; i++)
            {
                int j = i+len-1;
                if (s[i]==s[j] && (len<=2 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    ctr++;
                }
            }
        }
        return ctr;
    }
};
 {% endhighlight %}