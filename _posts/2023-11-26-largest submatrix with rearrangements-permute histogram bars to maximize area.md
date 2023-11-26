---
layout: mypost
title: "Largest Submatrix With Rearrangements - Permute histogram bars to maximize area"
tags: ["Array", "Greedy", "Sorting", "Matrix", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a binary matrix <code>matrix</code> of size <code>m x n</code>, and you are allowed to rearrange the <strong>columns</strong> of the <code>matrix</code> in any order.</p>

<p>Return <em>the area of the largest submatrix within </em><code>matrix</code><em> where <strong>every</strong> element of the submatrix is </em><code>1</code><em> after reordering the columns optimally.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40536-pm.png" style="width: 500px; height: 240px;" />
<pre>
<strong>Input:</strong> matrix = [[0,0,1],[1,1,1],[1,0,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40852-pm.png" style="width: 500px; height: 62px;" />
<pre>
<strong>Input:</strong> matrix = [[1,0,1,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[1,1,0],[1,0,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>matrix[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

# Solution:
Suppose you have a histogram represented by array `histogram` where `histogram[i]` denotes height of bar at `i`th position. We can permute the histogram in any order we want and we would like to know what is the largest area possible. How do we solve this?

Well, we can just sort the array `histogram` in reverse and check for `histogram[i]*(i+1)` since all `i+1` bars from `0` to `i`, both included, have heights equal to more than `histogram[i]`.

 {% highlight cpp %} 
int findMaxArea(vector<int> histogram)
{
    sort(histogram.rbegin(),histogram.rend()); // sort in reverse
    int maxArea = 0;
    for (int i=0; i<histogram.size(); i++)
        maxArea = max(maxArea, histogram[i]*(i+1));
    return maxArea;
}
 {% endhighlight %}

Now we use this logic in our situation. We can treat each row as the base of histogram going upto the top or till we see a zero.
Consider the following input matrix:
 {% highlight cpp %} 
0 0 1
1 1 1
1 0 1
 {% endhighlight %}
From here, we can get the following matrix as `heights`:
 {% highlight cpp %} 
0 0 1
1 1 2
2 0 3
 {% endhighlight %}
Each row can be treated as a histogram and from here we apply the logic discussed earlier to find the answer.

 {% highlight cpp %} 
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m,0));
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) 
          if(matrix[i][j]) heights[i][j] = (i==0) ? 1 : 1 + heights[i-1][j];
        int res = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> histogram = heights[i];
            sort(histogram.rbegin(),histogram.rend());
            for(int j=0; j<m && histogram[j]; j++) res = max(res, histogram[j]*(j+1));
        }
        return res;
    }
};
 {% endhighlight %}

$TC: O(n  m\log(m))$, $SC: O(nm)$