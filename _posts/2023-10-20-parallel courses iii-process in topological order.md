---
layout: mypost
title: "Parallel Courses III - Process in topological order"
tags: ["Array", "Dynamic Programming", "Graph", "Topological Sort", "C++", "Queue", "Hard"]
---
# Problem Statement:
<p>You are given an integer <code>n</code>, which indicates that there are <code>n</code> courses labeled from <code>1</code> to <code>n</code>. You are also given a 2D integer array <code>relations</code> where <code>relations[j] = [prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code> denotes that course <code>prevCourse<sub>j</sub></code> has to be completed <strong>before</strong> course <code>nextCourse<sub>j</sub></code> (prerequisite relationship). Furthermore, you are given a <strong>0-indexed</strong> integer array <code>time</code> where <code>time[i]</code> denotes how many <strong>months</strong> it takes to complete the <code>(i+1)<sup>th</sup></code> course.</p>

<p>You must find the <strong>minimum</strong> number of months needed to complete all the courses following these rules:</p>

<ul>
	<li>You may start taking a course at <strong>any time</strong> if the prerequisites are met.</li>
	<li><strong>Any number of courses</strong> can be taken at the <strong>same time</strong>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> number of months needed to complete all the courses</em>.</p>

<p><strong>Note:</strong> The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2021/10/07/ex1.png" style="width: 392px; height: 232px;" /></strong>

<pre>
<strong>Input:</strong> n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The figure above represents the given graph and the time required to complete each course. 
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.
</pre>

<p><strong class="example">Example 2:</strong></p>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2021/10/07/ex2.png" style="width: 500px; height: 365px;" /></strong>

<pre>
<strong>Input:</strong> n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= relations.length &lt;= min(n * (n - 1) / 2, 5 * 10<sup>4</sup>)</code></li>
	<li><code>relations[j].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>j</sub>, nextCourse<sub>j</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>j</sub> != nextCourse<sub>j</sub></code></li>
	<li>All the pairs <code>[prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code> are <strong>unique</strong>.</li>
	<li><code>time.length == n</code></li>
	<li><code>1 &lt;= time[i] &lt;= 10<sup>4</sup></code></li>
	<li>The given graph is a directed acyclic graph.</li>
</ul>

# Solution:
First of all we need to understand Topological ordering. It is an ordering of nodes in which for every edge $u ightarrow v$, $u$ comes before $v$. The basic logic is quite easy: Maintain a queue of nodes with zero inDegree.


Here is how you get topological ordering given a graph `G` and an array `inDegree`:

 {% highlight cpp %} 
queue<int>Q; vector<int> top_ord;
for(int i=0;i<n;i++) if(!inDegree[i]) Q.push(i);
while (!Q.empty())
{
    int u = Q.front(); Q.pop(); top_ord.push_back(u);
    for (int v: G[u]) if (!inDegree[v]--) Q.push(v);
}
 {% endhighlight %}

Now, we modify the code such that we process the graph in this ordering and we store the minimum time a course can be finished in the array `minTime`. Every time we have an edge $u ightarrow v$, we do `minTime[v] = max(minTime[v], minTime[u]+time[v]);` which means maximum end time of prerequisite courses and current course.


 {% highlight cpp %} 
class Solution 
{
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<vector<int>> G(n);
        vector<int> inDegree(n,0);
        for(auto &r: relations) 
        {
            int u=r[0]-1, v=r[1]-1;
            G[u].push_back(v);
            inDegree[v]++;
        }
        queue<int>Q;
        vector<int> minTime(n,0);
        for(int i=0;i<n;i++) if(!inDegree[i]) {Q.push(i); minTime[i]=time[i];}
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (int v: G[u])
            {
                minTime[v] = max(minTime[v], minTime[u]+time[v]);
                inDegree[v]--;
                if (!inDegree[v]) Q.push(v);
            }
        }
        return *max_element(minTime.begin(),minTime.end());
    }
};
 {% endhighlight %}