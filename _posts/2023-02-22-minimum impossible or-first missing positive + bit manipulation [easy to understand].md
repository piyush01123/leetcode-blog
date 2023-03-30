---
layout: mypost
title: "Minimum Impossible OR - First missing positive + Bit manipulation [Easy to understand]"
tags: ["C++", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong>&nbsp;integer array <code>nums</code>.</p>

<p>We say that an integer x is <strong>expressible</strong> from <code>nums</code> if there exist some integers <code>0 &lt;= index<sub>1</sub> &lt; index<sub>2</sub> &lt; ... &lt; index<sub>k</sub> &lt; nums.length</code> for which <code>nums[index<sub>1</sub>] | nums[index<sub>2</sub>] | ... | nums[index<sub>k</sub>] = x</code>. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of <code>nums</code>.</p>

<p>Return <em>the minimum <strong>positive non-zero integer</strong>&nbsp;that is not </em><em>expressible from </em><code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,3,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can show that 1 is the smallest number that is not expressible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
# Intuition
This problem seems similar to [First Missing Positive](https://leetcode.com/problems/first-missing-positive/). Here is a solution to that probelm:

 {% highlight cpp %} 
int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(),nums.end());
    int i = 1;
    while (i <= nums.size()){
        if (!numSet.count(i)) return i;
        i++;
    }
    return i;
}
 {% endhighlight %}
# Observation
Our solution is similar to the above in spirit. The crucial thing to notice is that if we have just powers of 2, we can construct all numbers upto the next power of 2 by their OR.

For example, given the array `[1,2,4,8,16]`, we can do `OR` between various elements to construct all numbers from 1 to 31. So the presence of other numbers in the middle like 3,5,6 etc. does not change the range of possible numbers. Hence these are the only ones that need to be checked.

# Code
 {% highlight cpp %} 
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) 
    {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int cur = 1;
        while (cur<INT_MAX)
        {
            if (!numSet.count(cur)) return cur;
            cur <<= 1;
        }
        return INT_MAX;
    }
};
 {% endhighlight %}