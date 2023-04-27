---
layout: mypost
title: "Restore The Array - Step-by-step recursive memoization"
tags: ["String", "Dynamic Programming", "C++", "Recursion", "Memoization", "Hard"]
---
# Problem Statement:
<p>A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits <code>s</code> and all we know is that all integers in the array were in the range <code>[1, k]</code> and there are no leading zeros in the array.</p>

<p>Given the string <code>s</code> and the integer <code>k</code>, return <em>the number of the possible arrays that can be printed as </em><code>s</code><em> using the mentioned program</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1000&quot;, k = 10000
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only possible array is [1000]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1000&quot;, k = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> There cannot be an array that was printed this way and has all integer &gt;= 1 and &lt;= 10.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1317&quot;, k = 2000
<strong>Output:</strong> 8
<strong>Explanation:</strong> Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only digits and does not contain leading zeros.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
Here is a baseline solution that works for small test cases.
 {% highlight cpp %} 
int numberOfArrays(string s, int k, int i=0) 
{
    if (i==s.length()) return 1;
    if (s[i]=='0') return 0;
    int j = i, res=0;
    string cur = "";
    while(j<s.length())
    {
        cur.push_back(s[j]);
        if (stoi(cur)>k) break;
        res += numberOfArrays(s, k, ++j);
    }
    return res;
}

 {% endhighlight %}
Now let us add memoization, add limits and mod the answer. 
 {% highlight cpp %} 
int mod = 1e9+7;
int dfs(string &s, int k, int i, vector<int>&memo)
{
    if (i==s.length()) return 1;
    if (memo[i]!=-1) return memo[i];
    if (s[i]=='0') return 0;
    int j = i, res=0;
    string cur = "";
    while(j<s.length())
    {
        cur.push_back(s[j]);
        if (cur.length()>=11 || ((cur.length()==10 && s[i]>'1')) || stoi(cur)>k) break;
        res += dfs(s, k, ++j, memo)%mod;
        res %=mod;
    }
    return memo[i] = res;
}
int numberOfArrays(string s, int k) 
{
    vector<int> memo(s.length(),-1);
    return dfs(s, k, 0, memo);
}
 {% endhighlight %}
**Analysis**: $O(m\log(k))$ TC, $O(m)$ SC where $m=\vert s \vert$.