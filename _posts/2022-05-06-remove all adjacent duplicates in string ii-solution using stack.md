---
layout: mypost
title: "Remove All Adjacent Duplicates in String II - Solution using stack"
tags: ["String", "Stack", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a string <code>s</code> and an integer <code>k</code>, a <code>k</code> <strong>duplicate removal</strong> consists of choosing <code>k</code> adjacent and equal letters from <code>s</code> and removing them, causing the left and the right side of the deleted substring to concatenate together.</p>

<p>We repeatedly make <code>k</code> <strong>duplicate removals</strong> on <code>s</code> until we no longer can.</p>

<p>Return <em>the final string after all such duplicate removals have been made</em>. It is guaranteed that the answer is <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcd&quot;, k = 2
<strong>Output:</strong> &quot;abcd&quot;
<strong>Explanation: </strong>There&#39;s nothing to delete.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;deeedbbcccbdaa&quot;, k = 3
<strong>Output:</strong> &quot;aa&quot;
<strong>Explanation: 
</strong>First delete &quot;eee&quot; and &quot;ccc&quot;, get &quot;ddbbbdaa&quot;
Then delete &quot;bbb&quot;, get &quot;dddaa&quot;
Finally delete &quot;ddd&quot;, get &quot;aa&quot;</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;pbbcggttciiippooaais&quot;, k = 2
<strong>Output:</strong> &quot;ps&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> only contains lowercase English letters.</li>
</ul>

# Solution:
Maintain a stack of (char, frequency) pair.
Here is how it works for a test case.
#### Input:
 {% highlight cpp %} 
s = "deeedbbcccbdaa", k = 3
 {% endhighlight %}
#### Dry run:
First column is where you are at. Second column is the stack at that time
 {% highlight cpp %} 
d : [['d', 1]] 
e : [['d', 1], ['e', 1]] 
e : [['d', 1], ['e', 2]] 
e : [['d', 1]] #You popped here
d : [['d', 2]] 
b : [['d', 2], ['b', 1]] 
b : [['d', 2], ['b', 2]] 
c : [['d', 2], ['b', 2], ['c', 1]] 
c : [['d', 2], ['b', 2], ['c', 2]] 
c : [['d', 2], ['b', 2]] #You popped here
b : [['d', 2]] #You popped here
d : [] #You popped here
a : [['a', 1]] 
a : [['a', 2]] 
 {% endhighlight %}
#### Answer:
Just join the elements in stack:
 {% highlight cpp %} 
"aa"
 {% endhighlight %}

Now we are ready to code!
# Code:
 {% highlight cpp %} 
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> H;
        for (char ch: s)
        {
            if (H.empty() || H.top().first!=ch) H.push({ch,1});
            else
            {
                H.top().second++;
                if (H.top().second==k) H.pop();
            }
        }
        string t="";
        while (!H.empty())
        {
            auto p=H.top(); 
            t+=string(p.second,p.first);
            H.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};
 {% endhighlight %}