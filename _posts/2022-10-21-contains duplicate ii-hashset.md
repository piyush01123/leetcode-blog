---
layout: mypost
title: "Contains Duplicate II - Hashset"
tags: ["Array", "Hash Table", "Sliding Window", "C++", "Easy"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <code>true</code> <em>if there are two <strong>distinct indices</strong> </em><code>i</code><em> and </em><code>j</code><em> in the array such that </em><code>nums[i] == nums[j]</code><em> and </em><code>abs(i - j) &lt;= k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1], k = 3
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,1,1], k = 1
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1,2,3], k = 2
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
The idea is to find if we have seen the current value already in the range. Since the search operation in hashset is constant time, hence our algorithm is efficient.
 {% highlight cpp %} 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_set<int> numset;
        for (int i=0; i<k && i<n; ++i)
        {
            if (numset.count(nums[i])) return true;
            numset.insert(nums[i]);
        }
        for (int i=k; i<n; ++i)
        {
            if (numset.count(nums[i])) return true;
            numset.insert(nums[i]);
            numset.erase(nums[i-k]);
        }
        return false;
    }
};
 {% endhighlight %}
 {% highlight cpp %} 
TC: O(n)
SC: O(k)
 {% endhighlight %}