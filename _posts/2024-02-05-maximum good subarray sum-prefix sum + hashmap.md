---
layout: mypost
title: "Maximum Good Subarray Sum - Prefix Sum + HashMap"
tags: ["Array", "Hash Table", "Prefix Sum", "C++", "Medium"]
---
# Problem Statement:
<p>You are given an array <code>nums</code> of length <code>n</code> and a <strong>positive</strong> integer <code>k</code>.</p>

<p>A <span data-keyword="subarray-nonempty">subarray</span> of <code>nums</code> is called <strong>good</strong> if the <strong>absolute difference</strong> between its first and last element is <strong>exactly</strong> <code>k</code>, in other words, the subarray <code>nums[i..j]</code> is good if <code>|nums[i] - nums[j]| == k</code>.</p>

<p>Return <em>the <strong>maximum</strong> sum of a <strong>good</strong> subarray of </em><code>nums</code>. <em>If there are no good subarrays</em><em>, return </em><code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5,6], k = 1
<strong>Output:</strong> 11
<strong>Explanation:</strong> The absolute difference between the first and last element<!-- notionvc: 2a6d66c9-0149-4294-b267-8be9fe252de9 --> must be 1 for a good subarray. All the good subarrays are: [1,2], [2,3], [3,4], [4,5], and [5,6]. The maximum subarray sum is 11 for the subarray [5,6].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,3,2,4,5], k = 3
<strong>Output:</strong> 11
<strong>Explanation:</strong> The absolute difference between the first and last element<!-- notionvc: 2a6d66c9-0149-4294-b267-8be9fe252de9 --> must be 3 for a good subarray. All the good subarrays are: [-1,3,2], and [2,4,5]. The maximum subarray sum is 11 for the subarray [2,4,5].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,-3,-4], k = 2
<strong>Output:</strong> -6
<strong>Explanation:</strong> The absolute difference between the first and last element<!-- notionvc: 2a6d66c9-0149-4294-b267-8be9fe252de9 --> must be 2 for a good subarray. All the good subarrays are: [-1,-2,-3], and [-2,-3,-4]. The maximum subarray sum is -6 for the subarray [-1,-2,-3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
Since we need to find subarray sum, we can use cumulative sum. So first of all we create an array of cumulative sum. We use `long long` dtype.
 {% highlight cpp %} 
vector<long long> cumsum(n); cumsum[0] = nums[0];
for(int i=1; i<n; i++) cumsum[i] = cumsum[i-1] + nums[i];
 {% endhighlight %}

We store the pairs `nums[i]-k: i` and `nums[i]+k: i` in a hashmap so that if we later find current value `nums[i]` in the hashmap then we have a viable candidate for a valid subarray. We can then find the maximum values of the candidates. If we did not find any candidate then we return zero.

 {% highlight cpp %} 
long long maximumSubarraySum(vector<int>& nums, int k) 
{
    int n = nums.size();
    long long res = LLONG_MIN;
    vector<long long> cumsum(n); cumsum[0] = nums[0];
    for(int i=1; i<n; i++) cumsum[i] = cumsum[i-1] + nums[i];
    unordered_map<int, vector<int>> H;
    for(int i=0; i<n; i++)
    {
        H[nums[i]-k].push_back(i);
        H[nums[i]+k].push_back(i);
        if(H.count(nums[i]))
        {
            for(int j: H[nums[i]])
            {
                long long candidate = cumsum[i] - (j>0 ? cumsum[j-1] : 0);
                res = max(res, candidate);
            }
        }
    }
    return res==LLONG_MIN ? 0 : res;
}
 {% endhighlight %}