---
layout: mypost
title: "Non-overlapping Intervals - Greedy cpp+python"
tags: ["Array", "Dynamic Programming", "Greedy", "Sorting", "Medium"]
---
# Problem Statement:
<p>Given an array of intervals <code>intervals</code> where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, return <em>the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,2],[2,3],[3,4],[1,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> [1,3] can be removed and the rest of the intervals are non-overlapping.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,2],[1,2],[1,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You need to remove two [1,2] to make the rest of the intervals non-overlapping.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,2],[2,3]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> You don&#39;t need to remove any of the intervals since they&#39;re already non-overlapping.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>-5 * 10<sup>4</sup> &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

# Solution:
```
bool mycomp(vector<int>&a, vector<int>&b)
{
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.size()==1) return 0;
        sort(intervals.begin(), intervals.end(), mycomp);
        int n=intervals.size(), curr=intervals[0][1], res=0;
        for (int i=1; i<n; i++)
        {
            if (intervals[i][0]>=curr) curr = intervals[i][1];
            else res ++;
        }
        return res;
    }
};
```

```
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda k: k[1])
        n, res, curr = len(intervals), 0, intervals[0][1]
        for i in range(1,n):
            if intervals[i][0]>=curr:
                curr = intervals[i][1]
			else:
			    res += 1
        return res
```