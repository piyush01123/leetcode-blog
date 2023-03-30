---
layout: mypost
title: "3Sum - Two pointers + Hashmap"
tags: ["Array", "Two Pointers", "Sorting", "Medium"]
---
# Problem Statement:
<p>Given an integer array nums, return all the triplets <code>[nums[i], nums[j], nums[k]]</code> such that <code>i != j</code>, <code>i != k</code>, and <code>j != k</code>, and <code>nums[i] + nums[j] + nums[k] == 0</code>.</p>

<p>Notice that the solution set must not contain duplicate triplets.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,0,1,2,-1,-4]
<strong>Output:</strong> [[-1,-1,2],[-1,0,1]]
<strong>Explanation:</strong> 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,1]
<strong>Output:</strong> []
<strong>Explanation:</strong> The only possible triplet does not sum up to 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,0,0]
<strong>Output:</strong> [[0,0,0]]
<strong>Explanation:</strong> The only possible triplet sums up to 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 3000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
The question would be very easy if not for the unique triplet thing. All we need to do is sort the array and for each element `A[i]` solve the `2Sum for sorted array` using the two pointer approach in the subarray `{A[i+1]..A[n-1]}`. 
```
vector<vector<int>> threeSum(vector<int>& nums, int target=0) {
	sort(nums.begin(),nums.end());
	int n = nums.size();
	vector<vector<int>>res;
	for (int i=0; i<n-2; i++)
	{
		int lo=i+1, hi=n-1;
		while (lo<hi)
		{
			if (nums[i]+nums[lo]+nums[hi]==target) 
			{
				res.push_back({nums[i],nums[lo],nums[hi]});
				lo++;hi--;
			}
			else if (nums[i]+nums[lo]+nums[hi]<target) lo++;
			else hi--;
		}
	}
	return res;
}
```
However this will give us duplicate triplets. 

To incorporate the unique triplet thing, we use Hashmaps to store results and before inserting a new result check if it exists already. We use the lowest of the triplet as key and the remaining two are inserted as a pair of ints. There is no particular logic for this choice. You could choose another schema as well.
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target=0) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,vector<pair<int,int>>>H;
        for (int i=0; i<n-2; i++)
        {
            int lo=i+1, hi=n-1;
            while (lo<hi)
            {
                if (nums[i]+nums[lo]+nums[hi]==target) 
                {
                    bool ok = true;
                    for (auto p: H[nums[i]])
                    {
                        if(nums[lo]==p.first && nums[hi]==p.second)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) 
                        H[nums[i]].push_back({nums[lo],nums[hi]}); 
                    lo++;hi--;
                }
                else if (nums[i]+nums[lo]+nums[hi]<target) lo++;
                else hi--;
            }
        }
        vector<vector<int>>res;
        for (auto kv: H)
            for (auto p: kv.second)
                res.push_back({kv.first,p.first,p.second});
        return res;
    }
};
```