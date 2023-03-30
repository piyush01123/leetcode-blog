---
layout: mypost
title: "Network Delay Time - Dijkstra method"
tags: ["Depth-First Search", "Breadth-First Search", "Graph", "Heap (Priority Queue)", "Shortest Path", "Medium"]
---
# Problem Statement:
<p>You are given a network of <code>n</code> nodes, labeled from <code>1</code> to <code>n</code>. You are also given <code>times</code>, a list of travel times as directed edges <code>times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>)</code>, where <code>u<sub>i</sub></code> is the source node, <code>v<sub>i</sub></code> is the target node, and <code>w<sub>i</sub></code> is the time it takes for a signal to travel from source to target.</p>

<p>We will send a signal from a given node <code>k</code>. Return <em>the <strong>minimum</strong> time it takes for all the</em> <code>n</code> <em>nodes to receive the signal</em>. If it is impossible for all the <code>n</code> nodes to receive the signal, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png" style="width: 217px; height: 239px;" />
<pre>
<strong>Input:</strong> times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> times = [[1,2,1]], n = 2, k = 1
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> times = [[1,2,1]], n = 2, k = 2
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= times.length &lt;= 6000</code></li>
	<li><code>times[i].length == 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 100</code></li>
	<li>All the pairs <code>(u<sub>i</sub>, v<sub>i</sub>)</code> are <strong>unique</strong>. (i.e., no multiple edges.)</li>
</ul>

# Solution:
**Dijsktra's Algorithm**: Maintain visited nodes in an array Q. Also maintain the distances from source in an array `dist`. Initially `Q = {source}` and `dist={INT_MAX,INT_MAX,INT_MAX...}`  and `dist[source]=0]`. Then while Q is not empty you do the following
- Find which node in Q has the minimum value in `dist` array. Call it `u`.
- For all nodes adjacent to `u`, check if `dist` value can be updated for them. If you update `dist` for any node `v`, then also add `v` to `Q`.

The standard implementation uses a min-heap.
```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph (n);
        for (auto item: times)
        {
            int u=item[0]-1, v=item[1]-1, w=item[2];
            graph[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
        Q.push({0, k-1});
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        while (!Q.empty())
        {
            auto top = Q.top();
            Q.pop();
            int u=top.second, d=top.first;
            for (auto edge: graph[u])
            {
                int v=edge.first, w=edge.second;
                if (d+w < dist[v])
                {
                    dist[v] = d+w;
                    Q.push({d+w, v});
                }
            }
        }
        int res = *max_element(dist.begin(), dist.end());
        return (res==INT_MAX)?-1:res;
    }
};
```
If you dont know about heap, the same logic can be implemented without heap as well with some additional cost but still gets an AC.
```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto edge: times)
        {
            int u=edge[0]-1, v=edge[1]-1, w=edge[2];
            graph[u].push_back({v,w});
        }
        vector<int> Q {k-1};
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        while (Q.size()>0)
        {
            int u, minStart=INT_MAX;
            for (int node: Q)
            {
                if (dist[node]<minStart)
                {
                    minStart=dist[node];
                    u = node;
                }
            }
            // u has the min distance out of all nodes in Q
            Q.erase(find(Q.begin(),Q.end(),u));
            for (auto edge: graph[u])
            {
                int v=edge.first, w=edge.second;
                if (dist[u]+w < dist[v])
                {
                    dist[v] = dist[u]+w;
                    Q.push_back(v);
                }
            }
        }
        int res = *max_element(dist.begin(),dist.end());
        return (res==INT_MAX)?-1:res;
    }
};
```