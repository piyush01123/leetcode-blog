---
layout: mypost
title: "Regular Expression Matching - Recursion and memoization"
tags: ["String", "Dynamic Programming", "Recursion", "C++", "Memoization", "Hard"]
---
# Problem Statement:
<p>Given an input string <code>s</code>&nbsp;and a pattern <code>p</code>, implement regular expression matching with support for <code>&#39;.&#39;</code> and <code>&#39;*&#39;</code> where:</p>

<ul>
	<li><code>&#39;.&#39;</code> Matches any single character.​​​​</li>
	<li><code>&#39;*&#39;</code> Matches zero or more of the preceding element.</li>
</ul>

<p>The matching should cover the <strong>entire</strong> input string (not partial).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aa&quot;, p = &quot;a&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> &quot;a&quot; does not match the entire string &quot;aa&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aa&quot;, p = &quot;a*&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> &#39;*&#39; means zero or more of the preceding element, &#39;a&#39;. Therefore, by repeating &#39;a&#39; once, it becomes &quot;aa&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab&quot;, p = &quot;.*&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> &quot;.*&quot; means &quot;zero or more (*) of any character (.)&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length&nbsp;&lt;= 20</code></li>
	<li><code>1 &lt;= p.length&nbsp;&lt;= 20</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
	<li><code>p</code> contains only lowercase English letters, <code>&#39;.&#39;</code>, and&nbsp;<code>&#39;*&#39;</code>.</li>
	<li>It is guaranteed for each appearance of the character <code>&#39;*&#39;</code>, there will be a previous valid character to match.</li>
</ul>

# Solution:
Without `*` character in `pattern`, we can have following logic for regex:
 {% highlight cpp %} 
bool isMatch(string s, string p)
{
    int slen = s.length(), plen = p.length();
    if ((plen==0) && (slen==0)) return true;
    if ((plen==0) || (slen==0)) return false;
    bool fm = (s[0]==p[0] || p[0]=='.');
    return fm && isMatch(s.substr(1), p.substr(1));
}
 {% endhighlight %}
Here `fm` denotes first character matching. Notice how we have enforced edge cases. We are saying that both `s` and `p` must end together for `true`. With the addition of `*` character in `pattern`, things change significantly. Now, `p` can end after `s` to account for zero matches in case of `*`, notice however that `s` cannot end after `p` has ended. Also, we will need to add check in `s` before getting `fm`.
 {% highlight cpp %} 
bool isMatch(string s, string p) 
{
    int slen = str.length(), plen = p.length();
    if (plen==0) return (slen==0);
    bool fm = (slen>0) && ((p[0]==s[0]) || (p[0]=='.'));
    if (plen>=2 && p[1]=='*')
        return isMatch(s,p.substr(2))||(fm && isMatch(s.substr(1), p));
    else
        return fm && isMatch(s.substr(1), p.substr(1));
}
 {% endhighlight %}
Here, the non-asterisk logic is same. However for asterisk, we have two cases: 0 match and 1 match. For zero match, we just increment two positions in `p` and for one match, we increment 1 position in `s` and again run with the same `p` (because `*` signifies any number of matches).

This passes for all tests but gives TLE at the end. 

Now, Let us add memoization to get AC.
 {% highlight cpp %} 
class Solution {
    vector<vector<int>> dp;
public:
    bool isMatch(string s, string p) 
    {
        int slen=s.length(), plen=p.length();
        if (plen==0) return (slen==0);
        if (dp.size()==0) dp = vector<vector<int>>(slen+1, vector<int>(plen+1,2));
        if (dp[slen][plen]!=2) return dp[slen][plen];
        bool fm = (slen>0) && (s[0]==p[0] || p[0]=='.');
        if (plen>=2 && p[1]=='*') 
            return dp[slen][plen] = (fm && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        else
            return dp[slen][plen] = fm && isMatch(s.substr(1), p.substr(1));
    }
};
 {% endhighlight %}
We get AC for this.

Same solution in java:
 {% highlight cpp %} 
class Solution {
    int[][] dp;
    public boolean isMatch(String s, String p) 
    {
        int slen=s.length(), plen=p.length();
        if (plen==0) return (slen==0);
        if (dp==null)
        {
            dp = new int[slen+1][plen+1];
            for (int[] row: dp) Arrays.fill(row, 2);
        }
        if (dp[slen][plen]!=2) return (dp[slen][plen]==1);
        boolean fm = (slen>0) && (s.charAt(0)==p.charAt(0) || p.charAt(0)=='.');
        boolean ret;
        if (plen>=2 && p.charAt(1)=='*') 
            ret = (fm && isMatch(s.substring(1), p)) || isMatch(s, p.substring(2));
        else
            ret = fm && isMatch(s.substring(1), p.substring(1));
        dp[slen][plen] = (ret)?1:0;
        return ret;
    }
};
 {% endhighlight %}