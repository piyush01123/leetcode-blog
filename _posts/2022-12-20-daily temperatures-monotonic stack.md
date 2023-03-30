---
layout: mypost
title: "Daily Temperatures - Monotonic stack"
tags: ["Array", "Stack", "Monotonic Stack", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array of integers <code>temperatures</code> represents the daily temperatures, return <em>an array</em> <code>answer</code> <em>such that</em> <code>answer[i]</code> <em>is the number of days you have to wait after the</em> <code>i<sup>th</sup></code> <em>day to get a warmer temperature</em>. If there is no future day for which this is possible, keep <code>answer[i] == 0</code> instead.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> temperatures = [73,74,75,71,69,72,76,73]
<strong>Output:</strong> [1,1,4,2,1,1,0,0]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,40,50,60]
<strong>Output:</strong> [1,1,1,0]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,60,90]
<strong>Output:</strong> [1,1,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;temperatures.length &lt;= 10<sup>5</sup></code></li>
	<li><code>30 &lt;=&nbsp;temperatures[i] &lt;= 100</code></li>
</ul>

# Solution:
# Intuition
The idea is to maintain a montonically decreasing stack of temperatures. As soon as you see a value greater than the stack top, you have found the answer for the numbers at stack top which have value lower than current value.

# Approach
We will use a monotonically decreasing stack. When we see a value smaller than stack top, just add it to the stack. But if we see a value higher than the stack top then we will update our answer for the stack top and pop from stack. We will keep doing this as long as current value is higher than stack top.

# Complexity
- Time complexity:
O(N) where N is the number of days.
- Space complexity:
O(N) because stack size could go up to the number of days N.

# Code
 {% highlight cpp %} 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        stack<pair<int,int>> stk;
        vector<int> res(n, 0);
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && temperatures[i]>stk.top().first)
            {
                res[stk.top().second] = i-stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i],i});
        }
        return res;
    }
};
 {% endhighlight %}