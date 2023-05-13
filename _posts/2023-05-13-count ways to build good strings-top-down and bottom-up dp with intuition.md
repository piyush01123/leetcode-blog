---
layout: mypost
title: "Count Ways To Build Good Strings - Top-down and bottom-up DP with intuition"
tags: ["Dynamic Programming", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>Given the integers <code>zero</code>, <code>one</code>, <code>low</code>, and <code>high</code>, we can construct a string by starting with an empty string, and then at each step perform either of the following:</p>

<ul>
	<li>Append the character <code>&#39;0&#39;</code> <code>zero</code> times.</li>
	<li>Append the character <code>&#39;1&#39;</code> <code>one</code> times.</li>
</ul>

<p>This can be performed any number of times.</p>

<p>A <strong>good</strong> string is a string constructed by the above process having a <strong>length</strong> between <code>low</code> and <code>high</code> (<strong>inclusive</strong>).</p>

<p>Return <em>the number of <strong>different</strong> good strings that can be constructed satisfying these properties.</em> Since the answer can be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> low = 3, high = 3, zero = 1, one = 1
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
One possible valid good string is &quot;011&quot;. 
It can be constructed as follows: &quot;&quot; -&gt; &quot;0&quot; -&gt; &quot;01&quot; -&gt; &quot;011&quot;. 
All binary strings from &quot;000&quot; to &quot;111&quot; are good strings in this example.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> low = 2, high = 3, zero = 1, one = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> The good strings are &quot;00&quot;, &quot;11&quot;, &quot;000&quot;, &quot;110&quot;, and &quot;011&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= low&nbsp;&lt;= high&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= zero, one &lt;= low</code></li>
</ul>

# Solution:
Let us say that for any value of `len`, the number of strings equal to `len` statisfying constraints is given by `f(len)` then we can say that
 {% highlight cpp %} 
f(len) = f(len-zero) + f(len-one)
 {% endhighlight %}
This is because to get strings of length `len`, we can either add `zero` zeros after strings of length `(len-zero)` or add `one` ones after strings of length `(len-one)`. The base case is that `f(0)=1` because there is one way to construct strings of length 0 which is the empty string `""`. Finally to get answer we can sum `f(i)` for `i` between `low` and `high` inclusive.

Here are 2 examples:
 {% highlight cpp %} 
Input: low = 3, high = 3, zero = 1, one = 1
f(3) = f(2)+f(2)
f(2) = f(1)+f(1)
f(1) = f(0)+f(0)
f(0) = 1
fvalues = [1,2,4,8]
Answer = 8

Input: low = 2, high = 3, zero = 1, one = 2
f(3) = f(2)+f(1)
f(2) = f(1)+f(0)
f(1) = f(0)
f(0) = 1
fvalues = [1,1,2,3]
Answer = 2+3 = 5
 {% endhighlight %}

**Naive recursion** - TLE:
 {% highlight cpp %} 
class Solution 
{
public:
    int util(int len, int zr, int on)
    {
        if(len<0) return 0;
        if (len==0) return 1;
        return util(len-zr, zr, on) + util(len-on, zr, on);
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int res = 0;
        for(int i=low; i<=high; i++) res += util(i,zero,one);
        return res;
    }
};
 {% endhighlight %}

**Recursion with memoization (Top Down DP)** - AC:
 {% highlight cpp %} 
class Solution 
{
    int mod = 1e9+7;
    vector<int> memo;
public:
    int util(int len, int zr, int on)
    {
        if(len<0) return 0;
        if (memo[len]!=-1) return memo[len];
        if (len==0) return memo[len]=1;
        return memo[len] = (util(len-zr, zr, on) + util(len-on, zr, on))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        memo = vector<int>(high+1, -1);
        int res = 0;
        for(int i=low; i<=high; i++){res += util(i,zero,one); res%=mod;}
        return res;
    }
};
 {% endhighlight %}

**Bottom-up DP** - AC:
 {% highlight cpp %} 
class Solution 
{
    int mod=1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int res = 0;
        vector<int>dp(high+1,0);
        dp[0]=1;
        for (int i=1; i<=high; i++)
        {
            dp[i] += (i-zero>=0) ? dp[i-zero] : 0;
            dp[i] += (i-one>=0) ? dp[i-one] : 0;
            dp[i] %= mod;
            if (i>=low) res+= dp[i];
            res %= mod;
        }
        return res;
    }
};
 {% endhighlight %}

*Complexity Analysis*: TC and SC of both accepted solutions are $$O(n)$$.
