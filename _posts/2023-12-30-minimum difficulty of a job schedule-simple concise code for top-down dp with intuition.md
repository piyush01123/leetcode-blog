---
layout: mypost
title: "Minimum Difficulty of a Job Schedule - Simple concise code for top-down DP with intuition"
tags: ["Array", "Dynamic Programming", "C++", "Memoization", "Hard"]
---
# Problem Statement:
<p>You want to schedule a list of jobs in <code>d</code> days. Jobs are dependent (i.e To work on the <code>i<sup>th</sup></code> job, you have to finish all the jobs <code>j</code> where <code>0 &lt;= j &lt; i</code>).</p>

<p>You have to finish <strong>at least</strong> one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the <code>d</code> days. The difficulty of a day is the maximum difficulty of a job done on that day.</p>

<p>You are given an integer array <code>jobDifficulty</code> and an integer <code>d</code>. The difficulty of the <code>i<sup>th</sup></code> job is <code>jobDifficulty[i]</code>.</p>

<p>Return <em>the minimum difficulty of a job schedule</em>. If you cannot find a schedule for the jobs return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/untitled.png" style="width: 365px; height: 370px;" />
<pre>
<strong>Input:</strong> jobDifficulty = [6,5,4,3,2,1], d = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> jobDifficulty = [9,9,9], d = 4
<strong>Output:</strong> -1
<strong>Explanation:</strong> If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> jobDifficulty = [1,1,1], d = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The schedule is one job per day. total difficulty will be 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= jobDifficulty.length &lt;= 300</code></li>
	<li><code>0 &lt;= jobDifficulty[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= d &lt;= 10</code></li>
</ul>

# Solution:
From reading the question, it is quite clear that it is a DP problem which leads us to the next problem: What is the recurrence relation? 

We can see that in addition to `d` ie the number of cuts, we also need to consider how far we have already come in the array, ie `pos`. Let us call our recursive function as `f(d,pos)`. Then the final answer can be written as `f(d,0)`.

Say we are at position `pos` and we need to apply a cut to the right of any index at or after `pos`. Let us call this cut index as `i`. Then the difficulty of current day is `max(jobDifficulty[pos:i])` and the remaining difficulty `rem` is `f(d-1,i+1)` because we have to make `d-1` cuts in the subarray starting from `i+1`. So the total difficulty becomes `max(jobDifficulty[pos:i]) + f(d-1,i+1)`. We have to minimize this for all valid values of cut indexes `i` and this minimized value is actually our answer for `f(d,pos)`. Mathematically, we can write this as:

$$
F(d,pos) = \min(G(d,pos,i)), i \in [pos,\vert A \vert -d]
$$

$$
G(d,pos,i) = \max(A_{pos,..,i}) + F(d-1,i+1)
$$


The limits of `i` in first equation comes because we need to place `d-1` cuts in the remaining array and for that we need to have at least `d` remaining length.

Base cases:
- $d > \vert A \vert $ then there is no way to design the schedule. Hence return -1.
- $d == 1$ Then we have to do all jobs in same day, so we return the maximum from `pos`.

 {% highlight cpp %} 
class Solution {
    vector<vector<int>> memo = vector<vector<int>>(20, vector<int>(2000,-1));
public:
    int minDifficulty(vector<int>& jobDifficulty, int d, int pos=0) 
    {
        if (d > jobDifficulty.size()) return -1;
        if(memo[d][pos]!=-1) return memo[d][pos];
        if (d==1) return *max_element(jobDifficulty.begin()+pos,jobDifficulty.end());
        int curMax = INT_MIN, res=INT_MAX;
        for(int i=pos; i<=jobDifficulty.size()-d; i++) 
        {
            int rem = minDifficulty(jobDifficulty, d-1, i+1);
            curMax = max(curMax, jobDifficulty[i]);
            res = min(res, curMax+rem);
        }
        return memo[d][pos] = res;
    }
};
 {% endhighlight %}

$ TC: O(n^2d) , SC: O(nd)$