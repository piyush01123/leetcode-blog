---
layout: mypost
title: "Maximum Profit in Job Scheduling - [Explained + Example] DP (Knapsack)+ OOP Faster than 97%"
tags: ["Array", "Binary Search", "Dynamic Programming", "Sorting", "C++", "Hard"]
---
# Problem Statement:
<p>We have <code>n</code> jobs, where every job is scheduled to be done from <code>startTime[i]</code> to <code>endTime[i]</code>, obtaining a profit of <code>profit[i]</code>.</p>

<p>You&#39;re given the <code>startTime</code>, <code>endTime</code> and <code>profit</code> arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.</p>

<p>If you choose a job that ends at time <code>X</code> you will be able to start another job that starts at time <code>X</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png" style="width: 380px; height: 154px;" /></strong></p>

<pre>
<strong>Input:</strong> startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
<strong>Output:</strong> 120
<strong>Explanation:</strong> The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png" style="width: 600px; height: 112px;" /> </strong></p>

<pre>
<strong>Input:</strong> startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
<strong>Output:</strong> 150
<strong>Explanation:</strong> The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png" style="width: 400px; height: 112px;" /></strong></p>

<pre>
<strong>Input:</strong> startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= startTime.length == endTime.length == profit.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= startTime[i] &lt; endTime[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= profit[i] &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
# Explanation
We sort the jobs by their ending times.
Now as we traverse through the `jobs` array, we are going to apply a logic similar to Knapsack:
- We maintain a `dp` array of `(endTime,maxProfitTillHere)` entities. We initialize it to `[(0,0)]`.
- For each job, we have two options: (i) To do this job: in this case we need to find the `maxProfit` till the time before the `startTime` of current job. (ii) Not do this job: in the case we will have the same `maxProfit`till the previous `dp` member.
- This is equivalent to the two options we have in a knapsack problem.

# Example
 {% highlight cpp %} 
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 {% endhighlight %}

Then sorted by endTime, we will have
 {% highlight cpp %} 
jobs = [(1,3,50),(2,4,10),(3,5,40),(3,6,70)]
 {% endhighlight %}
Initialize dp:
 {% highlight cpp %} 
dp = [(0,0)]`
 {% endhighlight %}
At i=0,
 {% highlight cpp %} 
option_A = 0+50
option_B = 0
 {% endhighlight %}
dp gets appended.
 {% highlight cpp %} 
dp = [(0,0),(3,50)]
 {% endhighlight %}
At i=1, Job = (2,4,10):
 {% highlight cpp %} 
option_A = 0+10
option_B = 50
 {% endhighlight %}
dp remains same.
 {% highlight cpp %} 
dp = [(0,0),(3,50)]
 {% endhighlight %}
At i=2, Job = (3,5,40):
 {% highlight cpp %} 
option_A = 50+40
option_B = 50
 {% endhighlight %}
dp gets appended
 {% highlight cpp %} 
dp = [(0,0),(3,50),(5,90)]
 {% endhighlight %}
At i=3, Job = (3,6,70):
 {% highlight cpp %} 
option_A = 50+70
option_B = 90
 {% endhighlight %}
dp gets appended
 {% highlight cpp %} 
dp = [(0,0),(3,50),(5,90),(6,120)]
 {% endhighlight %}
Finally answer is 120.

For implementation we create a custom class `Job`. For the DP part, we just use `startTime=-1` for all timestamps as it does not matter.
# C++ code:

 {% highlight cpp %} 
class Job
{
    public:
    int startTime, endTime, profit;
    Job(int s, int e, int p): startTime(s), endTime(e), profit(p) {}
    bool operator <  (const Job &other_job)const{return endTime  < other_job.endTime;}
    bool operator == (const Job &other_job)const{return endTime == other_job.endTime;}
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<Job> jobs;
        for (int i=0; i<n; i++)
            jobs.push_back(Job(startTime[i],endTime[i],profit[i]));
        sort(jobs.begin(),jobs.end());
        
        vector<Job> dp = vector<Job>{Job(-1,0,0)};
        for (const Job &job: jobs)
        {
            auto itr = upper_bound(dp.begin(),dp.end(),Job(-1,job.startTime,-1));
            int idx = itr-dp.begin()-1;
            int opt_A = dp[idx].profit + job.profit;
            int opt_B = dp.rbegin()->profit;
            if (opt_A > opt_B)
                dp.push_back(Job(-1,job.endTime, opt_A));
        }
        return dp.rbegin()->profit;
    }
};
 {% endhighlight %}