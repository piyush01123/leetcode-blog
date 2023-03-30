---
layout: mypost
title: "Factorial Trailing Zeroes - [Easy] One liner"
tags: ["Math", "C++", "Medium"]
---
# Problem Statement:
<p>Given an integer <code>n</code>, return <em>the number of trailing zeroes in </em><code>n!</code>.</p>

<p>Note that <code>n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> 3! = 6, no trailing zero.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> 5! = 120, one trailing zero.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you write a solution that works in logarithmic time complexity?</p>

# Solution:
You should notice that the number of zeros is bounded by the number of factors of 5 and its powers because 2 will have always more. So we just count the number of factors of each power of 5 from 1 to n using a simple divide operation.
 {% highlight cpp %} 
int trailingZeroes(int n) 
{
    return n/3125 + n/625 + n/125 + n/25 + n/5;
}
 {% endhighlight %}