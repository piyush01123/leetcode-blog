---
layout: mypost
title: "Zigzag Conversion - Easy Method"
tags: ["String", "C++", "Medium"]
---
# Problem Statement:
<p>The string <code>&quot;PAYPALISHIRING&quot;</code> is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)</p>

<pre>
P   A   H   N
A P L S I I G
Y   I   R
</pre>

<p>And then read line by line: <code>&quot;PAHNAPLSIIGYIR&quot;</code></p>

<p>Write the code that will take a string and make this conversion given a number of rows:</p>

<pre>
string convert(string s, int numRows);
</pre>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;PAYPALISHIRING&quot;, numRows = 3
<strong>Output:</strong> &quot;PAHNAPLSIIGYIR&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;PAYPALISHIRING&quot;, numRows = 4
<strong>Output:</strong> &quot;PINALSIGYAHRPI&quot;
<strong>Explanation:</strong>
P     I    N
A   L S  I G
Y A   H R
P     I
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;A&quot;, numRows = 1
<strong>Output:</strong> &quot;A&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of English letters (lower-case and upper-case), <code>&#39;,&#39;</code> and <code>&#39;.&#39;</code>.</li>
	<li><code>1 &lt;= numRows &lt;= 1000</code></li>
</ul>

# Solution:
We only need to notice that the row number for any character is decided by its modulus wrt $m=2*|s|-2$. This can be easily observed once you notice that the pattern starts repeating after it reaches the top row after one zigzag. Hence $m$ is the length of one zigzag. Next we need to check if each position is coming in the downward phase or the upward phase of zigzag and accordingly update that row.

 {% highlight cpp %} 
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows==1) return s;
        int m = 2*numRows - 2;
        vector<string> rows(numRows, "");
        for (int i=0; i<s.length(); i++)
        {
            int r = i%m;
            if (r<numRows) rows[r].push_back(s[i]);
            else rows[m-r].push_back(s[i]);
        }
        string res = "";
        for (string r: rows) res+=r;
        return res;
    }
};
 {% endhighlight %}

Time complexity: $O(n)$
