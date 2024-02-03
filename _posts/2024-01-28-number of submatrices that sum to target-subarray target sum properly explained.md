---
layout: mypost
title: "Number of Submatrices That Sum to Target - Subarray target sum properly explained"
tags: ["Array", "Hash Table", "Matrix", "Prefix Sum", "C++", "Hard"]
---
# Problem Statement:
<p>Given a <code>matrix</code>&nbsp;and a <code>target</code>, return the number of non-empty submatrices that sum to <font face="monospace">target</font>.</p>

<p>A submatrix <code>x1, y1, x2, y2</code> is the set of all cells <code>matrix[x][y]</code> with <code>x1 &lt;= x &lt;= x2</code> and <code>y1 &lt;= y &lt;= y2</code>.</p>

<p>Two submatrices <code>(x1, y1, x2, y2)</code> and <code>(x1&#39;, y1&#39;, x2&#39;, y2&#39;)</code> are different if they have some coordinate&nbsp;that is different: for example, if <code>x1 != x1&#39;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
<strong>Output:</strong> 4
<strong>Explanation:</strong> The four 1x1 submatrices that only contain 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[1,-1],[-1,1]], target = 0
<strong>Output:</strong> 5
<strong>Explanation:</strong> The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[904]], target = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= matrix.length &lt;= 100</code></li>
	<li><code>1 &lt;= matrix[0].length &lt;= 100</code></li>
	<li><code>-1000 &lt;= matrix[i] &lt;= 1000</code></li>
	<li><code>-10^8 &lt;= target &lt;= 10^8</code></li>
</ul>

# Solution:
Let us first explore the [Subarray Target Sum](https://leetcode.com/problems/subarray-sum-equals-k) problem. 

**Given array `nums` we want to know number of subarrays that sum to `target`. Here is how we do it.**

Suppose we are doing cumulative sum and at some index we have the value `sum`. Then we check if we have previously had any index at which the cumulative sum of `sum-target` was achieved. Because between those two indices the subarray sum is `sum-(sum-target)` or `target`. To check this, we use a hashmap.
 {% highlight cpp %} 
int subarraySum(vector<int>& nums, int target) 
{
    unordered_map<int,int> H; H[0]=1;
    int sum = 0, res = 0;
    for(int num: nums)
    {
        sum += num;
        if(H.count(sum-target)) res += H[sum-target];
        H[sum]++;
    }
    return res;
}
 {% endhighlight %}

With this method in mind, let us try to use it in our solution. The only problem is here we are dealing with 2-D. So, cumulative sum behaves differently. But what if we fix upper and lower row indices of our submatrix. Then the problem reduces to the subarray target sum problem.

 {% highlight cpp %} 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> matsum(m,vector<int>(n,0));
        for(int i=0; i<m; i++) for(int j=0; j<n; j++) 
        {
            int top = (i>0) ? matsum[i-1][j] : 0;
            int left = (j>0) ? matsum[i][j-1] : 0;
            int topleft = (min(i,j)>0) ? matsum[i-1][j-1] : 0;
            matsum[i][j] = top + left - topleft + matrix[i][j];
        }
        for(int i=0; i<m; i++) for(int ii=i; ii<m; ii++)
        {
            unordered_map<int,int> H; H[0]=1;
            for(int j=0; j<n; j++)
            {
                int sum = matsum[ii][j] - ((i>0 )? matsum[i-1][j] : 0);
                if(H.count(sum-target)) res += H[sum-target];
                H[sum]++;
            }
        }
        return res;
    }
};
 {% endhighlight %}

We can even morph it into a solution exactly like the subarray target sum problem.

 {% highlight cpp %} 
class Solution {
public:
    int subarraySum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> H; H[0]=1;
        int sum = 0, res = 0;
        for(int num: nums)
        {
            sum += num;
            if(H.count(sum-target)) res += H[sum-target];
            H[sum]++;
        }
        return res;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> matsum(m,vector<int>(n,0));
        for(int i=0; i<m; i++) for(int j=0; j<n; j++) 
            matsum[i][j] = ((i>0) ? matsum[i-1][j] : 0) + matrix[i][j];
        for(int i=0; i<m; i++) for(int ii=i; ii<m; ii++)
        {
            vector<int> A(n);
            for(int j=0; j<n; j++) A[j] = matsum[ii][j] - ((i>0) ? matsum[i-1][j] : 0);
            res += subarraySum(A, target);
        }
        return res;
    }
};
 {% endhighlight %}

Note: The solution is based loosely on Neetcode youtube video.