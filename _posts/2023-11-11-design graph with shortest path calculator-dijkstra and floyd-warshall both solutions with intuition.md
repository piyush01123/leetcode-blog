---
layout: mypost
title: "Design Graph With Shortest Path Calculator - Dijkstra and Floyd-Warshall both solutions with intuition"
tags: ["Graph", "Design", "Heap (Priority Queue)", "Shortest Path", "C++", "Hard"]
---
# Problem Statement:
<p>There is a <strong>directed weighted</strong> graph that consists of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>. The edges of the graph are initially represented by the given array <code>edges</code> where <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, edgeCost<sub>i</sub>]</code> meaning that there is an edge from <code>from<sub>i</sub></code> to <code>to<sub>i</sub></code> with the cost <code>edgeCost<sub>i</sub></code>.</p>

<p>Implement the <code>Graph</code> class:</p>

<ul>
	<li><code>Graph(int n, int[][] edges)</code> initializes the object with <code>n</code> nodes and the given edges.</li>
	<li><code>addEdge(int[] edge)</code> adds an edge to the list of edges where <code>edge = [from, to, edgeCost]</code>. It is guaranteed that there is no edge between the two nodes before adding this one.</li>
	<li><code>int shortestPath(int node1, int node2)</code> returns the <strong>minimum</strong> cost of a path from <code>node1</code> to <code>node2</code>. If no path exists, return <code>-1</code>. The cost of a path is the sum of the costs of the edges in the path.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/01/11/graph3drawio-2.png" style="width: 621px; height: 191px;" />
<pre>
<strong>Input</strong>
[&quot;Graph&quot;, &quot;shortestPath&quot;, &quot;shortestPath&quot;, &quot;addEdge&quot;, &quot;shortestPath&quot;]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
<strong>Output</strong>
[null, 6, -1, null, 6]

<strong>Explanation</strong>
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -&gt; 0 -&gt; 1 -&gt; 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -&gt; 1 -&gt; 3 with a total cost of 2 + 4 = 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1)</code></li>
	<li><code>edges[i].length == edge.length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub>, from, to, node1, node2 &lt;= n - 1</code></li>
	<li><code>1 &lt;= edgeCost<sub>i</sub>, edgeCost &lt;= 10<sup>6</sup></code></li>
	<li>There are no repeated edges and no self-loops in the graph at any point.</li>
	<li>At most <code>100</code> calls will be made for <code>addEdge</code>.</li>
	<li>At most <code>100</code> calls will be made for <code>shortestPath</code>.</li>
</ul>

# Solution:
### SOL 1: Dijkstra

#### Intuition for Dijkstra
Dijkstra is basically a greedy way to find distance from a source node to all other nodes. We start with source node and go to the nearest connected node. Then we use that node as source and go ahead exploring the graph.

Following is my solution with implementation of Dijkstra method using min-heap.
 {% highlight cpp %} 
#define pii pair<int,int>
class Graph 
{
    vector<vector<pii>> G;
public:
    Graph(int n, vector<vector<int>>& edges) 
    {
        G.resize(n);
        for (auto &edge: edges)
        {
            int u=edge[0], v=edge[1], w=edge[2];
            G[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        int u=edge[0], v=edge[1], w=edge[2];
        G[u].push_back({v,w});        
    }
    
    int shortestPath(int node1, int node2) 
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(G.size(),INT_MAX);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty())
        {
            pii ud = pq.top(); pq.pop();
            int d=ud.first, u=ud.second;
            for(pii vw: G[u])
            {
                int v = vw.first, w=vw.second;
                if (d+w<dist[v])
                {
                    dist[v] = d+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};
 {% endhighlight %}
BTW, it is also possible to implement Dijkstra's method without heaps but TC increases to `O(V^2)`. If you are interested, following code snippet will give you a glimpse of the implementation:
 {% highlight cpp %} 
vector<bool> visited(n,false);
vector<int> dist(n,INT_MAX);
dist[source]=0;

for(int ctr=0; ctr<n-1; ctr++)
{
    int u=-1, curMin=INT_MAX;
    for (int i=0; i<n; i++) if (!visited[i] && dist[i]<curMin)
    {
        u = i;
        curMin = dist[i];
    }
    visited[u] = true;
    for (pii vw: G[u])
    {
        int v=vw.first, w=vw.second;
        if (dist[u]+w < dist[v]) dist[v] = dist[u]+w;
    }
}
 {% endhighlight %}
I guess you can now see why priority queue will help.


### SOL 2: Floyd Warshall

#### Intuition for Floyd Warshall
Intuition is using DP. Consider shortest path from node `i` to node `j` using nodes `0,1,2,..k` and call it `D(i,j,k)`. Similarly define `D(i,j,k+1)`. Now let us see if we can find out `D(i,j,k+1)` using `D(i,j,k)`. Notice that `D(i,j,k+1)` can either use node number `k+1` or not use that node. If it does not use that node then answer becomes same as `D(i,j,k)` and if does use then answer becomes `D(i,k+1,k) + D(k+1,j,k)`. So we need to find the minimum of both:

 {% highlight cpp %} 
D(i,j,k+1) = min(D(i,j,k), D(i,k+1,k)+D(k+1,j,k))
 {% endhighlight %}
Hence if we update the initial distance matrix obtained by putting max value for `N` times then it will represent the graph accurately.

 {% highlight cpp %} 
class Graph 
{
    vector<vector<int>> dist;
public:
    Graph(int n, vector<vector<int>>& edges) 
    {
        dist.resize(n,vector<int>(n,INT_MAX/4));
        for(int i=0; i<n; i++) dist[i][i]=0;
        for (auto &edge: edges)
        {
            int u=edge[0], v=edge[1], w=edge[2];
            dist[u][v] = w;
        }
        for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    
    void addEdge(vector<int> edge) 
    {
        int u=edge[0], v=edge[1], w=edge[2], n=dist.size();
        for(int i=0; i<n; i++) for (int j=0; j<n; j++)
            dist[i][j] = min(dist[i][j], dist[i][u]+w+dist[v][j]);
    }
    
    int shortestPath(int node1, int node2) 
    {
        return (dist[node1][node2]==INT_MAX/4) ? -1 : dist[node1][node2];   
    }
};
 {% endhighlight %}
Dijkstra's method solution (using min-heap) has following complexities:
 {% highlight cpp %} 
Graph: O(E)
addEdge: O(1)
shortestPath: O((V+E)log(V))
 {% endhighlight %}

Floyd Warshall solution has following complexities:
 {% highlight cpp %} 
Graph: O(V^3)
addEdge: O(V^2)
shortestPath: O(1)
 {% endhighlight %}

Both solutions give us AC with good scores.