---
layout: mypost
title: "Make Sum Divisible by P - Two Sum logic on prefix mod"
tags: ["Array", "Hash Table", "Prefix Sum", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array of positive integers <code>nums</code>, remove the <strong>smallest</strong> subarray (possibly <strong>empty</strong>) such that the <strong>sum</strong> of the remaining elements is divisible by <code>p</code>. It is <strong>not</strong> allowed to remove the whole array.</p>

<p>Return <em>the length of the smallest subarray that you need to remove, or </em><code>-1</code><em> if it&#39;s impossible</em>.</p>

<p>A <strong>subarray</strong> is defined as a contiguous block of elements in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,4,2], p = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,3,5,2], p = 9
<strong>Output:</strong> 2
<strong>Explanation:</strong> We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], p = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= p &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
Basically the solution is to find a subarray whose mod equals that of the complete array. Let us call it M. The first task is to find `M`.
 {% highlight cpp %} 
int M = 0;
for(int num: nums) {M += num; M %= p;}
 {% endhighlight %}
Now we need to find subarray whose mod equals `M`. To do this we use a logic similar to [Two Sum](https://leetcode.com/problems/two-sum). The logic is that while traversing the array, at any position `i` we try to find a complement at an earlier index `j` in the `[0,i)` range.

Say the prefix sum modulus at `j` is a variable `a` and the prefix sum modulus at `i` is `a+M`. Then the modulus of the subarray is M and our task is done. Now as we traverse we are going to search for the variable `a` assuming the current modulus is `a+M`. 

So, say at index `i`, the current prefix sum modulus is `mod`. Then we need to find an index `j` where the prefix sum modulus is `mod-M`. But this can be negative. So we can just use `(mod-M+p) % p`.

To find this complement, we use the exact same logic of Two Sum ie using a hash map.


 {% highlight cpp %} cpp []
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int M = 0;
        for(int num: nums) {M += num; M %= p;}
        if(M==0) return 0;

        // Now we need to find smallest subarray whose mod is equal to M
        int n = nums.size(), mod = 0, res = INT_MAX;
        unordered_map<int,int> mods;
        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            mod += num; mod %= p;
            int complement = (mod+p-M) % p;

            if (mods.count(complement)) res = min(res, i-mods[complement]);
            if (complement==0) res = min(res, i+1);
            mods[mod] = i;
        }
        if (res==INT_MAX || res==n) return -1;
        return res;
    }
};

 {% endhighlight %}