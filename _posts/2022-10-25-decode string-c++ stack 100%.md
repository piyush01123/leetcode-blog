---
layout: mypost
title: "Decode String - C++ Stack 100%"
tags: ["String", "Stack", "Recursion", "C++", "Medium"]
---
# Problem Statement:
<p>Given an encoded string, return its decoded string.</p>

<p>The encoding rule is: <code>k[encoded_string]</code>, where the <code>encoded_string</code> inside the square brackets is being repeated exactly <code>k</code> times. Note that <code>k</code> is guaranteed to be a positive integer.</p>

<p>You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, <code>k</code>. For example, there will not be input like <code>3a</code> or <code>2[4]</code>.</p>

<p>The test cases are generated so that the length of the output will never exceed <code>10<sup>5</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;3[a]2[bc]&quot;
<strong>Output:</strong> &quot;aaabcbc&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;3[a2[c]]&quot;
<strong>Output:</strong> &quot;accaccacc&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;2[abc]3[cd]ef&quot;
<strong>Output:</strong> &quot;abcabccdcdcdef&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 30</code></li>
	<li><code>s</code> consists of lowercase English letters, digits, and square brackets <code>&#39;[]&#39;</code>.</li>
	<li><code>s</code> is guaranteed to be <strong>a valid</strong> input.</li>
	<li>All the integers in <code>s</code> are in the range <code>[1, 300]</code>.</li>
</ul>

# Solution:
Example: `3[a2[c]]` 
After traversal we will have the stack `('',3),(a,2)` and have the string `c` as the current string. 
From the stack we pop `num` and then `prevString`.
 {% highlight cpp %} 
curString = prevString + num*curString
 {% endhighlight %}
 
C++ code:
 {% highlight cpp %} 
class Solution {
public:
    string decodeString(string s) 
    {
        string curString="", curNum="";
        stack<string> stk;
        for (char ch: s)
        {
            if (ch=='[')
            {
                stk.push(curString);
                stk.push(curNum);
                curString = "";
                curNum = "";
            }
            else if (ch==']')
            {
                int num = stoi(stk.top());
                stk.pop();
                string prevString = stk.top();
                stk.pop();
                string temp = prevString;
                for (int i=0;i<num;i++) 
                    temp += curString;
                curString = temp;
            }
            else if (isdigit(ch))
                curNum += ch;
            else
                curString += ch;
        }
        return curString;
    }
};
 {% endhighlight %}