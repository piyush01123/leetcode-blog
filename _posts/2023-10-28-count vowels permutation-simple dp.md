---
layout: mypost
title: "Count Vowels Permutation - Simple DP"
tags: ["Dynamic Programming", "C++", "Hard"]
---
# Problem Statement:
<p>Given an integer <code>n</code>, your task is to count how many strings of length <code>n</code> can be formed under the following rules:</p>

<ul>
	<li>Each character is a lower case vowel&nbsp;(<code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, <code>&#39;u&#39;</code>)</li>
	<li>Each vowel&nbsp;<code>&#39;a&#39;</code> may only be followed by an <code>&#39;e&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;e&#39;</code> may only be followed by an <code>&#39;a&#39;</code>&nbsp;or an <code>&#39;i&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;i&#39;</code> <strong>may not</strong> be followed by another <code>&#39;i&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;o&#39;</code> may only be followed by an <code>&#39;i&#39;</code> or a&nbsp;<code>&#39;u&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;u&#39;</code> may only be followed by an <code>&#39;a&#39;.</code></li>
</ul>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo <code>10^9 + 7.</code></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> All possible strings are: &quot;a&quot;, &quot;e&quot;, &quot;i&quot; , &quot;o&quot; and &quot;u&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> All possible strings are: &quot;ae&quot;, &quot;ea&quot;, &quot;ei&quot;, &quot;ia&quot;, &quot;ie&quot;, &quot;io&quot;, &quot;iu&quot;, &quot;oi&quot;, &quot;ou&quot; and &quot;ua&quot;.
</pre>

<p><strong class="example">Example 3:&nbsp;</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 68</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10^4</code></li>
</ul>

# Solution:
The logic is that we store the number of words ending at each vowel in a variable. The pseudocode is this:
 {% highlight cpp %} 
a, e, i, o, u = e, a+i, a+e+o+u, i+u, a
 {% endhighlight %}
This happens each time we wish to increase size of word by one. The final answer is `a+e+i+o+u`. We add modulus operators for every addition to avoid overflow and also while returning the sum.

 {% highlight cpp %} 
class Solution {
public:
    int countVowelPermutation(int n) 
    {
        int mod=1e9+7;
        vector<int> A = {1,1,1,1,1};
        for(int i=1; i<n; i++)
            A = {A[1], \
                (A[0]+A[2])%mod, \
                (((A[0]+A[1])%mod+A[3])%mod+A[4])%mod, \
                (A[2]+A[4])%mod, \
                A[0]};
        return ((((A[0]+A[1])%mod+A[2])%mod+A[3])%mod+A[4])%mod;
    }
};
 {% endhighlight %}

$TC: O(n)$, $SC: O(1)$