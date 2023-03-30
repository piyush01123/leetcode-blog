---
layout: mypost
title: "4Sum II - Easy O(N^2) solution using HashMap"
tags: ["Array", "Hash Table", "Python", "C", "Medium"]
---
# Problem Statement:
<p>Given four integer arrays <code>nums1</code>, <code>nums2</code>, <code>nums3</code>, and <code>nums4</code> all of length <code>n</code>, return the number of tuples <code>(i, j, k, l)</code> such that:</p>

<ul>
	<li><code>0 &lt;= i, j, k, l &lt; n</code></li>
	<li><code>nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0</code></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The two tuples are:
1. (0, 0, 0, 1) -&gt; nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -&gt; nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>n == nums3.length</code></li>
	<li><code>n == nums4.length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>-2<sup>28</sup> &lt;= nums1[i], nums2[i], nums3[i], nums4[i] &lt;= 2<sup>28</sup></code></li>
</ul>

# Solution:
Create a hashmap H of all possible sums of `nums1` and `nums2` in O(N^2) time.
Then traverse `nums3`X`nums4` in O(N^2) time and each time check membership in H.
Easy-peasy!

C++ version:
 {% highlight python %} 
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res=0;
        unordered_map<int,int> H;
        for (int n1: nums1) for (int n2: nums2) H[n1+n2]++;
        for (int n3: nums3) for (int n4: nums4) if (H.count(-(n3+n4))) res+=H[-(n3+n4)];
        return res;
    }
};
 {% endhighlight %}
Python version:
 {% highlight python %} 
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        H = collections.defaultdict(int)
        res = 0
        for n1 in nums1:
            for n2 in nums2:
                H[n1+n2]+=1
        for n3 in nums3:
            for n4 in nums4:
                if -(n3+n4) in H:
                    res += H[-(n3+n4)]
        return res
 {% endhighlight %}