---
layout: mypost
title: "Course Schedule II - [Two methods] Kahn's Algorithm and DFS"
tags: ["Depth-First Search", "Breadth-First Search", "Graph", "Topological Sort", "C++", "Medium"]
---
# Problem Statement:
<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>

<ul>
	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
</ul>

<p>Return <em>the ordering of courses you should take to finish all courses</em>. If there are many valid answers, return <strong>any</strong> of them. If it is impossible to finish all courses, return <strong>an empty array</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
<strong>Output:</strong> [0,2,1,3]
<strong>Explanation:</strong> There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 1, prerequisites = []
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= numCourses * (numCourses - 1)</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>All the pairs <code>[a<sub>i</sub>, b<sub>i</sub>]</code> are <strong>distinct</strong>.</li>
</ul>

# Solution:
Construct adjacency list graph and inDegrees array. Then run Kahn's algorithm.
# Kahn's algorithm
- Create two arrays `noIncoming` and `doable` both empty initially
- Put all courses which have no prerequisites in `noIncoming`
- While `noIncoming` is not empty 
	- Pop a node from `noIncoming` and insert in `doable`
	- Traverse through adjacency list of this node and for each destination node in this adjacency list:
	  - Decrement `inDegree` of this destination node. This is equivalent to breaking an edge
	  - if `InDegree` is 0 then insert it into `noIncoming`

 {% highlight cpp %} 
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> G;
        unordered_map<int,int> inDegrees;
        vector<int> noIncoming, doable;
        
        for (auto p: prerequisites)
        {
            G[p[1]].push_back(p[0]);
            inDegrees[p[0]]++;
        }
        
        for (int i=0; i<numCourses; i++)
            if (inDegrees[i]==0)
                noIncoming.push_back(i);
        
        while (noIncoming.size()>0)
        {
            int curr = noIncoming.back();
            noIncoming.pop_back();
            doable.push_back(curr);
            for (int nbd: G[curr])
            {
                inDegrees[nbd]--;
                if (inDegrees[nbd]==0)
                    noIncoming.push_back(nbd);
            }
        }
        if (doable.size() < numCourses) return {};
        return doable;
    }
};
 {% endhighlight %}

# DFS
Here we will need to maintain state of node during DFS. We do it using three colors: White(0) for not visited, Black(1) for visited and completed and Grey(2) for currently visiting and inside recursion.
 {% highlight cpp %} 
// Colors: 0-Not visited, 1-visited and done, 2-visiting and recursion going on
class Solution {
    bool possible = true;

public:
    void dfs(unordered_map<int,vector<int>> &G, unordered_map<int,int> &colors, int curr, vector<int> &doable)
    {
        if (!this->possible) return;
        colors[curr] = 2;
        for (int nbd: G[curr])
        {
            if (colors[nbd]==0)
                dfs(G,colors,nbd,doable);
            else if (colors[nbd]==2)
                this->possible = false;
        }
        colors[curr] = 1;
        doable.push_back(curr);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> G;
        unordered_map<int,int> colors;
        vector<int> doable;
        
        for (auto p: prerequisites)
            G[p[1]].push_back(p[0]);
        for (int i=0; i<numCourses; i++)
            colors[i] = 0;

        for (int curr=0; curr<numCourses; curr++)
        {
            if (colors[curr]==0)
                dfs(G, colors, curr, doable);
        }
        
        if (!this->possible) return {};
        reverse(doable.begin(), doable.end());
        return doable;
    }
};
 {% endhighlight %}