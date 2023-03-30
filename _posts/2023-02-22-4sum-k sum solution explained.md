---
layout: mypost
title: "4Sum - K Sum solution explained"
tags: ["Array", "Two Pointers", "Sorting", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array <code>nums</code> of <code>n</code> integers, return <em>an array of all the <strong>unique</strong> quadruplets</em> <code>[nums[a], nums[b], nums[c], nums[d]]</code> such that:</p>

<ul>
	<li><code>0 &lt;= a, b, c, d&nbsp;&lt; n</code></li>
	<li><code>a</code>, <code>b</code>, <code>c</code>, and <code>d</code> are <strong>distinct</strong>.</li>
	<li><code>nums[a] + nums[b] + nums[c] + nums[d] == target</code></li>
</ul>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
<strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2,2,2], target = 8
<strong>Output:</strong> [[2,2,2,2]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
# Explanation
We will generalize 2-sum to K-Sum.

## Revision of 2 Sum
There are two main ways to solve 2 Sum in $O(n)$ time. Let us look at both. We will not look at finding whether two sum exists but return all such pairs (with repitition if repititions are present). For the 2nd method, let us assume that the array was given to us in sorted order. We will talk about this assumption later.

### 2 Sum using HashSet: $O(n)$ time, $O(n)$ space
 {% highlight cpp %} 
vector<vector<int>> twoSum(vector<int>nums, target)
{
    vector<vector<int>> res;
    unordered_set<int> complements;
    for (int n: nums)
    {
        if (complements.count(n)) vec.push_back({target-n, target});
        complements.insert(target-n);
    }
    return res;
}
 {% endhighlight %}

### 2 Sum using double pointer: $O(n)$ time, $O(1)$ space
**Note:** We had assumed `nums` to be pre-sorted.
 {% highlight cpp %} 
vector<vector<int>> twoSum(vector<int>nums, target)
{
    vector<vector<int>> res;
    int lo=0, hi=nums.size()-1;
    while(lo<hi)
    {
        int cur = nums[lo] + nums[hi];
        if (cur==target)
        {
            res.push_back({nums[lo],nums[hi]});
            lo++;
            hi--;
        }
        else if (cur<target) lo++;
        else hi--;
    }
    return res;
}
 {% endhighlight %}

Now to generalize this to K-Sum we can have a recursive function such that `KSum` for `K` will be created using `KSum` for `K-1`. When we reach `K=2` we will use the `twoSum` that we have written earlier.

Now the crucial thing to note is that for `K=3,4,5,...` we will always have a situation where `TC` is at least $O(n^2)$, hence it makes sense to pre-sort array in $O(n\log(n))$ time and use the 2nd method. It also helps in keeping track of unique subsets because otherwise we will have to sort the subset each time before adding to `res`.


# Code
 {% highlight cpp %} 
#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return KSum(nums, target, 4, 0);
    }
    vector<vector<int>> KSum(vector<int>&nums, ll target, \
                             int K, int start)
    {
        if (start>=nums.size()) return {};
        if (target<(ll)nums[start]*K || target>(ll)nums.back()*K) return {};
        if (K==2) return twoSum(nums, target, start);
        set<vector<int>> res;
        for (int i=start; i<nums.size(); i++)
        {
            vector<vector<int>> kSumPrev = KSum(nums, target-nums[i], K-1, i+1);
            for (auto subset: kSumPrev)
            {
                subset.push_back(nums[i]);
                res.insert(subset);
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
    vector<vector<int>> twoSum(vector<int>&nums, ll target, int start)
    {
        vector<vector<int>> res;
        int lo=start, hi=nums.size()-1;
        while(lo<hi)
        {
            ll cur = (ll)nums[lo] + nums[hi];
            if (cur==target)
            {
                res.push_back({nums[lo],nums[hi]});
                lo++;
                hi--;
            }
            else if (cur<target) lo++;
            else hi--;
        }
        return res;
    }
};
 {% endhighlight %}
# Complexity
`TC`: $O(n^3)$
`SC`: $O(n)$