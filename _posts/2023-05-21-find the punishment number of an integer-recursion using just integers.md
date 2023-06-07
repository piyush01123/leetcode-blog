---
layout: mypost
title: "Find the Punishment Number of an Integer - Recursion using just integers"
tags: ["Math", "Recursion", "C++", "Medium"]
---
# Problem Statement:
<p>Given a positive integer <code>n</code>, return <em>the <strong>punishment number</strong></em> of <code>n</code>.</p>

<p>The <strong>punishment number</strong> of <code>n</code> is defined as the sum of the squares of all integers <code>i</code> such that:</p>

<ul>
	<li><code>1 &lt;= i &lt;= n</code></li>
	<li>The decimal representation of <code>i * i</code> can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals <code>i</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 182
<strong>Explanation:</strong> There are exactly 3 integers i that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 37
<strong>Output:</strong> 1478
<strong>Explanation:</strong> There are exactly 4 integers i that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

# Solution:
We can take advantage of the fact that the target $n$ is in the range $1 \leq n \leq 1000$. This means that at any point, there are only three valid ways to split the candidate number from the right: single-digit suffix, two-digit suffix and three-digit suffix.

 {% highlight cpp %} 
class Solution {
public:
    bool util(int candidate, int target) //candidate=i*i, target=i, ex: (1296,36)
    {
        if (target<0) return false;
        if (candidate==0) return false;
        bool a =  (candidate==target);
        bool b = util(candidate/10, target-candidate%10);
        bool c = util(candidate/100, target-candidate%100);
        bool d = util(candidate/1000, target-candidate%1000);
        return (a|b|c|d);
    }
    int punishmentNumber(int n) 
    {
        int res=0;
        for(int i=1; i<=n; i++) if(util(i*i, i)) res+= i*i;
        return res;
    }
};
 {% endhighlight %}
