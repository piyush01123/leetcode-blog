---
layout: mypost
title: "Binary Trees With Factors - DP on sorted array"
tags: ["Array", "Hash Table", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array of unique integers, <code>arr</code>, where each integer <code>arr[i]</code> is strictly greater than <code>1</code>.</p>

<p>We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node&#39;s value should be equal to the product of the values of its children.</p>

<p>Return <em>the number of binary trees we can make</em>. The answer may be too large so return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [4, 2, 2]</code></pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,4,5,10]
<strong>Output:</strong> 7
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]</code>.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>2 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li>All the values of <code>arr</code> are <strong>unique</strong>.</li>
</ul>

# Solution:
Firstly let us sort the array and store the values of the array in a `(value, index)` hashmap `amap`. Now let us find the answer `dp[i]` for the subarray ending at index `i`. Later we can sum up all values in `dp` array to get the final answer. We can quickly see that 
 {% highlight cpp %} 
dp[i] = 1 + sum(dp[j]*dp[k])
 {% endhighlight %}
where `j, k` are chosen such that `arr[j]*arr[k] = arr[i]`. We have an extra one for the singleton tree `[a[i]]`. We can write this into following solution:

 {% highlight cpp %} 
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n = arr.size(), mod = 1000000007, res=0;
        sort(arr.begin(), arr.end());
        unordered_map<int,int> amap;
        for(int i=0;i<n;i++)amap[arr[i]] = i;
        vector<long> dp(n);
        for (int i=0; i<n; i++)
        {
            dp[i] = 1;
            for (int j=0; j<i; j++) if (arr[i]%arr[j]==0 && amap.count(arr[i]/arr[j])) 
                dp[i] += dp[j] * dp[amap[arr[i]/arr[j]]] % mod;
            dp[i]%= mod;
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};
 {% endhighlight %}

 {% highlight cpp %} 
TC: O(n^2)
SC: O(n)
 {% endhighlight %}