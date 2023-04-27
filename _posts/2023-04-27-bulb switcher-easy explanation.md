---
layout: mypost
title: "Bulb Switcher - Easy explanation"
tags: ["Math", "Brainteaser", "C++", "Medium"]
---
# Problem Statement:
<p>There are <code>n</code> bulbs that are initially off. You first turn on all the bulbs, then&nbsp;you turn off every second bulb.</p>

<p>On the third round, you toggle every third bulb (turning on if it&#39;s off or turning off if it&#39;s on). For the <code>i<sup>th</sup></code> round, you toggle every <code>i</code> bulb. For the <code>n<sup>th</sup></code> round, you only toggle the last bulb.</p>

<p>Return <em>the number of bulbs that are on after <code>n</code> rounds</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bulb.jpg" style="width: 421px; height: 321px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 0
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
Consider `ith` bulb (1-indexed) and consider how many times it will be flipped. The answer is it will be flipped at step number of all of its factors. 
For example:
 {% highlight cpp %} 
1->1
2->1,2
3->1,3
4->1,2,4
5->1,5
6->1,2,3,6
7->1,7
8->1,2,4,8
9->1,3,9
10->1,2,5,10
 {% endhighlight %}
Hence, if `i` has even number of factors, it will eventually return to its initial state however if `i` has odd number of factors, it will be  eventually be in flipped states. This odd number of factors also correspnds to perfect squares. 

**Hence, essentially the problem translates to "How many perfect squares in the `[1,n]` range?".** 

Here is a straightforward solution using `sqrt` from [cmath](https://cplusplus.com/reference/cmath/sqrt/).
 {% highlight cpp %} 
int bulbSwitch(int n) 
{
    return (int)sqrt((double)n);
}
 {% endhighlight %}
Now complexity of `sqrt` is $O(1)$ because it uses FISR method. [Read my gist for more details on FISR method](https://gist.github.com/piyush01123/bb9a736e5b1a895e8c1e0e841e963a40).


Following solution is $O(\log(n))$ method for finding integer square root.
 {% highlight cpp %} 
int bulbSwitch(int n) 
{
    if (n==0) return n;
    if (n<4) return 1;
    int lo=0, hi=n/2, mid;
    while (lo<=hi)
    {
        mid = lo + (hi-lo)/2;
        if (n/mid==mid) return mid;
        else if (n/mid > mid) lo = mid+1;
        else if (n/mid < mid) hi = mid-1;
    }
    return lo-1;
}
 {% endhighlight %}
