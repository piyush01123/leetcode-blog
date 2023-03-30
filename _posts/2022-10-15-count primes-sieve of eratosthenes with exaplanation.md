---
layout: mypost
title: "Count Primes - Sieve of Eratosthenes with Exaplanation"
tags: ["Array", "Math", "Enumeration", "Number Theory", "C++", "Medium"]
---
# Problem Statement:
<p>Given an integer <code>n</code>, return <em>the number of prime numbers that are strictly less than</em> <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 0
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 5 * 10<sup>6</sup></code></li>
</ul>

# Solution:
Sieve of Eratosthenes is the well known algorithm for such count/print primes type problems and the algorithm was invented by him ~2200 years ago!


The algorithm is based on following easily verifiable observation:
**If a number n is not prime then n will have one or more prime factors in the range `[2,sqrt(n)]`**
 {% highlight cpp %} 
class Solution {
public:
    int countPrimes(int n)
    {
        if (n<2) return 0;
        vector<bool> prime(n+1,true);
        for (int p=2; p*p<=n; ++p)
        {
            if (!prime[p]) continue;
            for (int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
        
        int ctr = 0;
        for (int p=2; p<n; ++p) ctr += prime[p];
        return ctr;
    }
};
 {% endhighlight %}
If you are wondering about the inner loop why it starts from `p*p` ie we are marking `[p*p, p*p+p, p*p+2p, p*p+3p,..,n]` and so on and why we are not starting from p ie `[p, 2p, 3p,..,n]`, it is because `[p,2p,..,p*p)` will already be marked by some other smaller prime.