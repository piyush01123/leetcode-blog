---
layout: mypost
title: "Capacity To Ship Packages Within D Days - Binary search with proper explanation"
tags: ["Array", "Binary Search", "C++", "Medium"]
---
# Problem Statement:
<p>A conveyor belt has packages that must be shipped from one port to another within <code>days</code> days.</p>

<p>The <code>i<sup>th</sup></code> package on the conveyor belt has a weight of <code>weights[i]</code>. Each day, we load the ship with packages on the conveyor belt (in the order given by <code>weights</code>). We may not load more weight than the maximum weight capacity of the ship.</p>

<p>Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within <code>days</code> days.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> weights = [1,2,3,4,5,6,7,8,9,10], days = 5
<strong>Output:</strong> 15
<strong>Explanation:</strong> A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> weights = [3,2,2,4,1,4], days = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> weights = [1,2,3,1,1], days = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong>
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= weights.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 500</code></li>
</ul>
# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We need to find the minimum possible capacity that will work. So, we can think of the problem as a search problem with a test of whether it will work at a given capacity. If we want to find the answer in a range `[0,M]` then we can apply the test at `M/2` and if it works then we recurse in the lower half and if it does not work then we recurse in the upper half. In this way we can come up with a binary search.

# Approach
<!-- Describe your approach to solving the problem. -->
To create the test described above we need to write a function `bool possible(int capacity, int days, vector<int>&weights)` which will return `true` if it is possible and `false` if it is not possible to work with `capacity`. We will use this for binary search as described previously.


# Code
 {% highlight cpp %} 
class Solution {
public:
    bool possible(int capacity, int days, vector<int>&weights)
    {
        int n=weights.size(), i=0, ctr=0;
        while(i<n)
        {
            if (weights[i]>capacity) return false;
            int cur = 0;
            while(i<n && cur+weights[i]<=capacity)
            {
                cur += weights[i];
                i++;
            }
            ctr ++;
        }
        return (ctr<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int lo=0, hi=INT_MAX;
        while (lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if (possible(mid, days, weights)) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};
 {% endhighlight %}

# Complexity
- Time complexity: $O(n \log(M))$ where $M$ is the maximum possible value of `capacity`. It can be the maximum value of `weights` array but in our implementation we have taken it to be `INT_MAX` since the difference is trivial anyway (in log scale).
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(1)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
