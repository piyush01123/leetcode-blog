---
layout: mypost
title: "Sum of Subarray Minimums - Monotonic Stack + DP"
tags: ["Array", "Dynamic Programming", "Stack", "Monotonic Stack", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array of integers arr, find the sum of <code>min(b)</code>, where <code>b</code> ranges over every (contiguous) subarray of <code>arr</code>. Since the answer may be large, return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [3,1,2,4]
<strong>Output:</strong> 17
<strong>Explanation:</strong> 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [11,81,94,43,3]
<strong>Output:</strong> 444
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 3 * 10<sup>4</sup></code></li>
</ul>

# Solution:
# Intuition + Approach
<!-- Describe your first thoughts on how to solve this problem. -->
The intuition is that while traversing, we will maintain a 1-D DP array such that
 {% highlight cpp %} 
dp[i] = f(0,i) + f(1,i) + f(2,i) + ... + f(i,i)
 {% endhighlight %}
where 
 {% highlight cpp %} 
f(j,i) = Minimum from indices j to i (inclusive)
 {% endhighlight %}

Once we are done, we can add the `dp` array to get our answer.

## Example
 {% highlight cpp %} 
arr = [8,6,3,5,4,9,2]
 {% endhighlight %}
For this example, we want that after we are done, the DP should look like:
 {% highlight cpp %} 
dp = [8,12,9,14,17,26,14]
 {% endhighlight %}
We can see that how this matches our expectation:
 {% highlight cpp %} 
dp[0] = 8
dp[1] = 6+6
dp[2] = 3+3+3
dp[3] = 3+3+3+5
dp[4] = 3+3+3+4+4
dp[5] = 3+3+3+4+4+9
dp[6] = 2+2+2+2+2+2+2
 {% endhighlight %}
As expected we can sum the `dp` array to get our answer 100.

## How to create this DP array
We will use a monotonic stack (MS) for this. The basic setting for a MS is:
 {% highlight cpp %} 
stack<int> stk;
for (int i=0; i<n; i++)
{
    while (!stk).empty() && stk.top()>=A[i]) stk.pop();
    stk.push(A[i]);
}
 {% endhighlight %}
Here we will store the indices instead of the values. For each iteration in `i`, once we are done withe the popping, we can create `dp[i]` as follows:
- If the stack is empty, it means the current element is the smallest of all elements in `(0,i)` range. Hence, `dp[i] = A[i]*(i+1)` corresponding to ranges `(0,i)`, `(1,i)`, `(2,i)`, ...., `(i,i)`.

- If the stack is not empty and the top of the stack is `j`, then, for the ranges `(0,i)`, `(1,i)`, `(2,i)`, ..., `(j,i)`, the minimum element is stored in `dp[j]` (their sum) and for the ranges `(j+1,i)`, `(j+2,i)`, ..., `(i,i)`, the minimum element is `A[i]`. Hence, `dp[i] = dp[j] + A[i]*(i-j)`

# Complexity
- Time complexity: $O(n)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(n)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
 {% highlight cpp %} 
#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size(), mod=1000000007;
        ll res = 0;
        vector<ll> dp(n,-1);
        stack<int> stk;
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && arr[i]<=arr[stk.top()]) stk.pop();
            if (!stk.empty())
            {
                int j = stk.top();
                dp[i] = dp[j] + arr[i]*(i-j);
            } 
            else dp[i] = arr[i]*(i+1);
            stk.push(i);
        }
        for (int x: dp) res+=x;
        return (int)(res%mod);
    }
};
 {% endhighlight %}