---
layout: mypost
title: "Longest Increasing Subsequence - Two DP solutions"
tags: ["Array", "Binary Search", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code>, return <em>the length of the longest <strong>strictly increasing </strong></em><span data-keyword="subsequence-array"><em><strong>subsequence</strong></em></span>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,9,2,5,3,7,101,18]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,0,3,2,3]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [7,7,7,7,7,7,7]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2500</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b>&nbsp;Can you come up with an algorithm that runs in&nbsp;<code>O(n log(n))</code> time complexity?</p>

# Solution:
Fastest O(N log N) solution in C++:
 {% highlight cpp %} 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int n: nums)
        {
            if (sub.size()==0 || n > sub[sub.size()-1])
                sub.push_back(n);
            else
            {
                vector<int>::iterator it = lower_bound(sub.begin(),sub.end(),n);
                *it = n;
            }
        }
        return sub.size();
    }
};
 {% endhighlight %}

O(N^2) solution:
C++:
 {% highlight cpp %} 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++) for(int j=0;j<i;j++) if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1); 
        return *max_element(dp.begin(), dp.end());
    }
};
 {% endhighlight %}
Python:
 {% highlight cpp %} 
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1 for _ in range(n)]
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)
 {% endhighlight %}
Java:
 {% highlight cpp %} 
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for(int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }
        }
        return Arrays.stream(dp).max().getAsInt();
    }
}
 {% endhighlight %}
JavaScript:
 {% highlight cpp %} 
var lengthOfLIS = function(nums) {
    var n = nums.length;
    var dp = Array(n);
    dp.fill(1);
    for(let i=0; i<n; i++)
        {
            for (let j=0; j<i; j++)
                {
                    if (nums[i]>nums[j]){
                        dp[i] = Math.max(dp[i],dp[j]+1);
                    }
                }
        }
    return Math.max(...dp);
};
 {% endhighlight %}