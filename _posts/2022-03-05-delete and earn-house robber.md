---
layout: mypost
title: "Delete and Earn - House Robber"
tags: ["Array", "Hash Table", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>You are given an integer array <code>nums</code>. You want to maximize the number of points you get by performing the following operation any number of times:</p>

<ul>
	<li>Pick any <code>nums[i]</code> and delete it to earn <code>nums[i]</code> points. Afterwards, you must delete <b>every</b> element equal to <code>nums[i] - 1</code> and <strong>every</strong> element equal to <code>nums[i] + 1</code>.</li>
</ul>

<p>Return <em>the <strong>maximum number of points</strong> you can earn by applying the above operation some number of times</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,3,3,3,4]
<strong>Output:</strong> 9
<strong>Explanation:</strong> You can perform the following operations:
- Delete a 3 to earn 3 points. All 2&#39;s and 4&#39;s are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
Notice that whichever number you choose to earn, you can earn all instances of that number and none of the number to the left or right.
Hence, we need to find the frequency or rather the total points possible for earning each number and then run a House Robber on that.

House robber can be solved using DP. Here I have given two ways to solve it: using a DP array or using just two integer variables.

 {% highlight cpp %} 
class Solution {
public:
    int rob_v1(vector<int> money)
    {
        int n=money.size();
        if (n==1) return money[0];
        vector<int> dp(n,0);
        dp[0] = money[0]; dp[1] = max(money[0], money[1]);
        for (int i=2; i<n; i++) dp[i] = max(dp[i-2]+money[i], dp[i-1]);
        return dp[n-1];
    }
    
    int rob_v2(vector<int>  money)
    {
        int n=money.size();
        if (n==1) return money[0];
        int a=money[0], b=max(money[0], money[1]), b_old;
        for (int i=2; i<n; i++)
        {
            b_old = b;
            b = max(a+money[i], b);
            a = b_old;
        }
        return b;
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 10000;
        vector<int> points(maxNum, 0);
        for (int n: nums) points[n-1]+=n;
        return rob_v2(points);
    }
};
 {% endhighlight %}