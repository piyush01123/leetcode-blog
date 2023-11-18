---
layout: mypost
title: "Bus Routes - BFS solution with intuition"
tags: ["Array", "Hash Table", "Breadth-First Search", "C++", "Hard"]
---
# Problem Statement:
<p>You are given an array <code>routes</code> representing bus routes where <code>routes[i]</code> is a bus route that the <code>i<sup>th</sup></code> bus repeats forever.</p>

<ul>
	<li>For example, if <code>routes[0] = [1, 5, 7]</code>, this means that the <code>0<sup>th</sup></code> bus travels in the sequence <code>1 -&gt; 5 -&gt; 7 -&gt; 1 -&gt; 5 -&gt; 7 -&gt; 1 -&gt; ...</code> forever.</li>
</ul>

<p>You will start at the bus stop <code>source</code> (You are not on any bus initially), and you want to go to the bus stop <code>target</code>. You can travel between bus stops by buses only.</p>

<p>Return <em>the least number of buses you must take to travel from </em><code>source</code><em> to </em><code>target</code>. Return <code>-1</code> if it is not possible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> routes = [[1,2,7],[3,6,7]], source = 1, target = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= routes.length &lt;= 500</code>.</li>
	<li><code>1 &lt;= routes[i].length &lt;= 10<sup>5</sup></code></li>
	<li>All the values of <code>routes[i]</code> are <strong>unique</strong>.</li>
	<li><code>sum(routes[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= routes[i][j] &lt; 10<sup>6</sup></code></li>
	<li><code>0 &lt;= source, target &lt; 10<sup>6</sup></code></li>
</ul>

# Solution:
Let us first start with a simpler problem and then extend our solution to the given problem statement.

Assume for a moment that the problem was a simple graph with adjacency list `G` and we wanted to find shortest distance between two nodes `source` and `target`. Then we would use the following logic:

 {% highlight cpp %} 
int shortestDistanceBFS(vector<vector<int>>&G, int source, int target)
{
    queue<int> Q;
    Q.push(source);
    int ctr=0;
    vector<int> visited (n, false);
    while (!Q.empty())
    {
        for (int i=Q.size(); i>0; i--)
        {
            int cur = Q.front(); Q.pop();
            if (cur==target) return ctr;
            visited[cur] = true;
            for (int nbd: G[cur]) if (!visited[nbd]) Q.push(nbd);
        }
        ctr ++;
    }
    return -1;
}
 {% endhighlight %}

Now, our problem statement has bus routes that denote reachability. So we first store the bus routes available from a node in `reachable_routes`. We also create a boolean array `traversed_routes` to store the routes that have been checked already as we proceed. Now we modify the following line:
 {% highlight cpp %} 
for (int nbd: G[cur]) if (!visited[nbd]) Q.push(nbd);
 {% endhighlight %}
We change this to work in our setting. For this we first find out all reachable routes from `cur`, check if the route has been traversed or not using `traversed_routes` and then if not traversed, we add all nodes of the route to our queue. The following snippet does all of this:
 {% highlight cpp %} 
for (int route_id: reachable_routes[cur])
{
    if (!traversed_routes[route_id]) 
    {
        traversed_routes[route_id] = true;                        
        for (int nbd: routes[route_id]) if(!visited.count(nbd)) Q.push(nbd);
    }
}

 {% endhighlight %}

Here is the complete solution:
 {% highlight cpp %} 
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        unordered_map<int,vector<int>> reachable_routes;
        for (int i=0; i<routes.size(); i++)
            for (int node: routes[i]) reachable_routes[node].push_back(i);
        queue<int> Q;
        Q.push(source);
        int ctr = 0;
        unordered_set<int> visited;
        vector<bool> traversed_routes(routes.size(), false);
        while(!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                int cur = Q.front();
                Q.pop();
                visited.insert(cur);
                if (cur==target) return ctr;
                for (int route_id: reachable_routes[cur])
                {
                    if (!traversed_routes[route_id]) 
                    {
                        traversed_routes[route_id] = true;                        
                        for (int nbd: routes[route_id]) if(!visited.count(nbd)) Q.push(nbd);
                    }
                }
            }
            ctr++;
        }
        return -1;
    }
};
 {% endhighlight %}