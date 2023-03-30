---
layout: mypost
title: "132 Pattern - O(N^3), O(N^2), O(N log N) and O(N) solutions"
tags: ["Array", "Binary Search", "Stack", "Monotonic Stack", "Ordered Set", "C++", "Medium"]
---
# Problem Statement:
<p>Given an array of <code>n</code> integers <code>nums</code>, a <strong>132 pattern</strong> is a subsequence of three integers <code>nums[i]</code>, <code>nums[j]</code> and <code>nums[k]</code> such that <code>i &lt; j &lt; k</code> and <code>nums[i] &lt; nums[k] &lt; nums[j]</code>.</p>

<p>Return <code>true</code><em> if there is a <strong>132 pattern</strong> in </em><code>nums</code><em>, otherwise, return </em><code>false</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no 132 pattern in the sequence.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,4,2]
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a 132 pattern in the sequence: [1, 4, 2].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,3,2,0]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
# O(N^3)  solution
Brute force to test all triplets for the required condition. This requires a triple for loop.
Pseudocode:
 {% highlight cpp %} 
for i in 0..n
	for j in in i+1..n
		for k in  j+1..n
		  if nums[i]<nums[k]<nums[j]
		    return true
return false
 {% endhighlight %}
This is trivial to implement and guaranteed to be TLE so no need to code this.

# O(N^2) solution
We can eliminate one for loop!
We can do this by keeping track of min element to the left as `minLeft`. If `minLeft==nums[i]`, we need not test for the condition and if not, we try to find an appropriate item in the right side.
 {% highlight cpp %} 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return false;
        int minLeft=nums[0];
        for (int j=0; j<n; j++)
        {
            minLeft = min(minLeft, nums[j]);
            if (minLeft==nums[j]) continue;
            for (int k=n-1; k>j; k--)
                if (nums[k]>minLeft && nums[k]<nums[j])
                    return true;
        }
        return false;
    }
};
 {% endhighlight %}
Unfortunately this gives TLE on the last test case. So, we need to improve.

# O(N log N) solution
We can replace the 2nd for loop that we use to find the right element by a binary search heuristic.
We traverse the array right to left and maintain a sorted array by inserting at the appropriate location obtained using binary search. We also maintain a very important array `largestSmaller` such that `largestSmaller[i] =`  `largest of the items to the right of nums[i] which are all smaller than nums[i]`. Essentially this is the `2` in the `132` that we need. Now if we get anything less than this element in the left side, we have a triplet.
 {% highlight cpp %} 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(), minLeft=INT_MAX, minRight=INT_MAX;
        if (n<3) return false;
        vector<int> largestSmaller(n,0), sortedRight;
        for (int i=n-1;i>=0;i--)
        {
            minRight = min(minRight, nums[i]);
            if (nums[i]==minRight){
                sortedRight.insert(sortedRight.begin(),nums[i]);
                largestSmaller[i]=nums[i];
            }
            else
            {
                vector<int>::iterator low=lower_bound(sortedRight.begin(), sortedRight.end(), nums[i]);
                int pos=low-sortedRight.begin();
                largestSmaller[i] = sortedRight[pos-1];
                sortedRight.insert(sortedRight.begin()+pos, nums[i]);
            }
        }
        for (int i=0; i<n; i++)
        {
            minLeft = min(minLeft, nums[i]);
            if (minLeft<nums[i] && minLeft<largestSmaller[i] && nums[i]>largestSmaller[i]) return true;
        }
        return false;
    }
};
 {% endhighlight %}

Sadly this O(N log N) solution also gives a TLE.
However, [I knew of a bug in LC where it accepts python but says TLE for cpp](https://leetcode.com/discuss/general-discussion/1743011/c-tle-vs-python-ac-issue) and decided to try coding the exact same logic in python
 {% highlight cpp %} 
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n, minLeft, minRight = len(nums), 10**9+1, 10**9+1
        if n<3: return False
        largestSmaller, sortedRight = [0 for _ in range(n)],[]
        for i in range(n-1,-1,-1):
            minRight = min(minRight, nums[i])
            if nums[i]==minRight:
                sortedRight.insert(0, nums[i])
                largestSmaller[i] = nums[i]
            else:
                pos = bisect_left(sortedRight, nums[i])
                largestSmaller[i] = sortedRight[pos-1]
                sortedRight.insert(pos, nums[i])
        for i in range(n):
            minLeft = min(minLeft, nums[i])
            if minLeft<largestSmaller[i]<nums[i]:
                return True
        return False
 {% endhighlight %}
With this, we get an AC !!
However this may not work in a real life coding test, so we need to get an O(N) solution

# O(N) solution
The idea is similar as above. The only trick is that instead of using a sorted array to find the right element, we can use a stack. We traverse right to left and store all elements smaller than the current element in a monotonically decreasing stack. Then later if ever we find that the current element is less than the element at the top of the stack, we have found a triplet.

 {% highlight cpp %} 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return false;
        stack<int> rightNums;
        int largestSmaller = INT_MIN;
        for (int i=n-1; i>=0; i--)
        {
            if (nums[i]<largestSmaller) return true;
            else
            {
                while (rightNums.size()>0 && nums[i]>rightNums.top())
                {
                    largestSmaller = rightNums.top();
                    rightNums.pop();
                }
            }
            rightNums.push(nums[i]);
        }
        return false;
    }
};
 {% endhighlight %}
Example:
`[1,8,5,6,7,9,10]`
Then right to left we get a stream 10,9,7,6,5,8,1
So, we get `stack=10,9,7,6,5`
Then when we see 8: `stack=10,9,8` (5,6,7 are popped in that order) and `largestSmaller=7`. This means from now on we can look for a potential triplet if we see anything less than 7 (like 1) and the triplet is (1,8,7)


This solution gives us an AC and also places us at the top 5%.