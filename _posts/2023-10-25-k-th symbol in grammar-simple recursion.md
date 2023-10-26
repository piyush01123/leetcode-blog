---
layout: mypost
title: "K-th Symbol in Grammar - Simple Recursion"
tags: ["Math", "Bit Manipulation", "Recursion", "C++", "Medium"]
---
# Problem Statement:
<p>We build a table of <code>n</code> rows (<strong>1-indexed</strong>). We start by writing <code>0</code> in the <code>1<sup>st</sup></code> row. Now in every subsequent row, we look at the previous row and replace each occurrence of <code>0</code> with <code>01</code>, and each occurrence of <code>1</code> with <code>10</code>.</p>

<ul>
	<li>For example, for <code>n = 3</code>, the <code>1<sup>st</sup></code> row is <code>0</code>, the <code>2<sup>nd</sup></code> row is <code>01</code>, and the <code>3<sup>rd</sup></code> row is <code>0110</code>.</li>
</ul>

<p>Given two integer <code>n</code> and <code>k</code>, return the <code>k<sup>th</sup></code> (<strong>1-indexed</strong>) symbol in the <code>n<sup>th</sup></code> row of a table of <code>n</code> rows.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> row 1: <u>0</u>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
row 1: 0
row 2: <u>0</u>1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 2, k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
row 1: 0
row 2: 0<u>1</u>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>n - 1</sup></code></li>
</ul>

# Solution:
Firstly, let us write down the pattern that emerges from the pattern `0->01`, `1->10` for `n=1,2,3,4,5`:
 {% highlight cpp %} 
0
01
0110
01101001
0110100110010110
 {% endhighlight %}
We can quickly notice a pattern that given the `kthGrammar(n) = kthGrammar(n-1) + complement(kthGrammar(n-1))` ie prefix remains same and complement is concatenated. So hence, given `(n, k)`, if we are on the right half of length `L`, we can get its value from the complement of `(n-1,k-L/2)` and if in the left half, we can simply take the value from the answer for `(n-1,k)`. 

We can use this to write the following recursive solution.
 {% highlight cpp %} 
class Solution 
{
public:
    int kthGrammar(int n, int k) 
    {
        if (n==1) return 0;
        int L = (1<<(n-1));
        if (k<=L/2) return kthGrammar(n-1, k);
        else return 1^kthGrammar(n-1, k-L/2);
    }
};
 {% endhighlight %}