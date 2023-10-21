---
layout: mypost
title: "Parallel Courses II - DFS + DP + Bitmasking"
tags: ["Dynamic Programming", "Bit Manipulation", "Graph", "Bitmask", "C++", "Depth-First Search", "Combinatorics", "Hard"]
---
# Problem Statement:
<p>You are given an integer <code>n</code>, which indicates that there are <code>n</code> courses labeled from <code>1</code> to <code>n</code>. You are also given an array <code>relations</code> where <code>relations[i] = [prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code>, representing a prerequisite relationship between course <code>prevCourse<sub>i</sub></code> and course <code>nextCourse<sub>i</sub></code>: course <code>prevCourse<sub>i</sub></code> has to be taken before course <code>nextCourse<sub>i</sub></code>. Also, you are given the integer <code>k</code>.</p>

<p>In one semester, you can take <strong>at most</strong> <code>k</code> courses as long as you have taken all the prerequisites in the <strong>previous</strong> semesters for the courses you are taking.</p>

<p>Return <em>the <strong>minimum</strong> number of semesters needed to take all courses</em>. The testcases will be generated such that it is possible to take every course.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/22/leetcode_parallel_courses_1.png" style="width: 269px; height: 147px;" />
<pre>
<strong>Input:</strong> n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> The figure above represents the given graph.
In the first semester, you can take courses 2 and 3.
In the second semester, you can take course 1.
In the third semester, you can take course 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/22/leetcode_parallel_courses_2.png" style="width: 271px; height: 211px;" />
<pre>
<strong>Input:</strong> n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The figure above represents the given graph.
In the first semester, you can only take courses 2 and 3 since you cannot take more than two per semester.
In the second semester, you can take course 4.
In the third semester, you can take course 1.
In the fourth semester, you can take course 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>0 &lt;= relations.length &lt;= n * (n-1) / 2</code></li>
	<li><code>relations[i].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>i</sub>, nextCourse<sub>i</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>i</sub> != nextCourse<sub>i</sub></code></li>
	<li>All the pairs <code>[prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code> are <strong>unique</strong>.</li>
	<li>The given graph is a directed acyclic graph.</li>
</ul>

# Solution:
This problem contains concepts of DFS + DP + Bitmask + combinatorics. The underlying idea is that for every K-combination of viable courses at a moment, choose the combination that minimizes answer. Bitmask represents courses with 1 for not done and 0 for done. Initially we have all ones (no course is done) and we stop when `mask` has all zeros (all courses are done). 

We need a utility function with signature `vector<vector<int>> combinations(vector<int>v, int k)` which given an array of numbers `v`, gives us all possible combinations of size `k`. Viable courses are stored in array `doable`.

 {% highlight cpp %} 
class Solution 
{
    unordered_map<int,int>cache;
public:
    int dfs(int n, vector<vector<int>>&G, vector<int> inDegree, int mask, int k)
    {
        if (mask==0) return 0;
        if (cache.count(mask)) return cache[mask];
        vector<int> doable;
        for(int i=0; i<n; i++) if((mask&(1<<i)) && !inDegree[i]) doable.push_back(i);
        int res = INT_MAX;
        for (auto comb: combinations(doable, k))
        {
            int newMask = mask;
            vector<int> newInDegree = inDegree;
            for (int u: comb)
            {
                newMask ^= (1<<u);
                for(int v: G[u]) newInDegree[v]--;
            }
            res = min(res, 1+dfs(n, G, newInDegree, newMask, k));
        }
        return cache[mask] = res;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) 
    {
        vector<vector<int>> G(n);
        vector<int> inDegree(n,0);
        for(auto r: relations)
        {
            int u=r[0]-1, v=r[1]-1;
            G[u].push_back(v);
            inDegree[v]++;
        }
        return dfs(n, G, inDegree, (1<<n)-1, k);
    }

    vector<vector<int>> combinations(vector<int>v, int k)
    {
        if (v.size()<=k) return {v};
        vector<int> cur;
        vector<vector<int>> res;
        generateCombinations(v, k, cur, 0, res);
        return res;
    }

    void generateCombinations(vector<int>&v, int k, vector<int>&cur, int index, vector<vector<int>>&res)
    {
        if (k==0){res.push_back(cur); return;}
        if (index==v.size()) return;
        cur.push_back(v[index]);
        generateCombinations(v, k-1, cur, index+1, res);
        cur.pop_back();
        generateCombinations(v, k, cur, index+1, res);
    }
};
 {% endhighlight %}