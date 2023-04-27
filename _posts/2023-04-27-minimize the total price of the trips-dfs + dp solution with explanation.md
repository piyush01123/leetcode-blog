---
layout: mypost
title: "Minimize the Total Price of the Trips - DFS + DP solution with explanation"
tags: ["Array", "Dynamic Programming", "Tree", "Depth-First Search", "C++", "Memoization", "Hard"]
---
# Problem Statement:
<p>There exists an undirected and unrooted tree with <code>n</code> nodes indexed from <code>0</code> to <code>n - 1</code>. You are given the integer <code>n</code> and a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Each node has an associated price. You are given an integer array <code>price</code>, where <code>price[i]</code> is the price of the <code>i<sup>th</sup></code> node.</p>

<p>The <strong>price sum</strong> of a given path is the sum of the prices of all nodes lying on that path.</p>

<p>Additionally, you are given a 2D integer array <code>trips</code>, where <code>trips[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> indicates that you start the <code>i<sup>th</sup></code> trip from the node <code>start<sub>i</sub></code> and travel to the node <code>end<sub>i</sub></code> by any path you like.</p>

<p>Before performing your first trip, you can choose some <strong>non-adjacent</strong> nodes and halve the prices.</p>

<p>Return <em>the minimum total price sum to perform all the given trips</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/03/16/diagram2.png" style="width: 541px; height: 181px;" />
<pre>
<strong>Input:</strong> n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The diagram above denotes the tree after rooting it at node 2. The first part shows the initial tree and the second part shows the tree after choosing nodes 0, 2, and 3, and making their price half.
For the 1<sup>st</sup> trip, we choose path [0,1,3]. The price sum of that path is 1 + 2 + 3 = 6.
For the 2<sup>nd</sup> trip, we choose path [2,1]. The price sum of that path is 2 + 5 = 7.
For the 3<sup>rd</sup> trip, we choose path [2,1,3]. The price sum of that path is 5 + 2 + 3 = 10.
The total price sum of all trips is 6 + 7 + 10 = 23.
It can be proven, that 23 is the minimum answer that we can achieve.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/03/16/diagram3.png" style="width: 456px; height: 111px;" />
<pre>
<strong>Input:</strong> n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The diagram above denotes the tree after rooting it at node 0. The first part shows the initial tree and the second part shows the tree after choosing node 0, and making its price half.
For the 1<sup>st</sup> trip, we choose path [0]. The price sum of that path is 1.
The total price sum of all trips is 1. It can be proven, that 1 is the minimum answer that we can achieve.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>edges</code> represents a valid tree.</li>
	<li><code>price.length == n</code></li>
	<li><code>price[i]</code> is an even integer.</li>
	<li><code>1 &lt;= price[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= trips.length &lt;= 100</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
</ul>

# Solution:
There are 2 steps in the solution:
1. Finding the route for each trip and after finishing all trips, we must have data of which node occurred how many times in all trips combined. Note that the graph has a tree structure, so we can be sure that there is a unique route for each trip. Let us call this data as `contrib` which is array of size `n` and stores contributions of each node to the trips (combined).
2. Finding the minimum price for all these trips keeping the halving rule in mind.

Step 1 is pretty straightforward. For each trip, you just run DFS starting from source with appending current node in an array and if you meet the destination you have found the route.

In step 2, we run DFS again from node 0. Note that at any point during the DFS, if the parent node price was halved, then we have no choice but to return current node price without halving. But if the parent node price was not halved, we can either choose to halve or not halve the current node price and so we return the minimum of both choices. We maintain a 2-D array of size `(n,2)` to memoize results. Since, we are assuming node 0 has no parent and in the final answer price of node 0 may or may not be halved so we return `dfs(cur=0, par=-1, parHalved=false)`.

 {% highlight cpp %} 
void getContrib(vector<vector<int>>&G, vector<int>&contrib, vector<int>path, int cur, int dest, int par)
{
    path.push_back(cur);
    if (cur==dest)
    {
        for (int node: path) contrib[node]++;
        return;
    }
    for (int nbd: G[cur])
    {
        if (nbd==par) continue;
        getContrib(G, contrib, path, nbd, dest, cur);
    }
    path.pop_back();
}

int dfs(vector<vector<int>>&G, vector<vector<int>>&memo, vector<int>&contrib, vector<int>& prices, int cur, int par, bool parHalved)
{
    if (memo[cur][parHalved]!=-1) return memo[cur][parHalved];
    int resCurNotHalved = prices[cur]*contrib[cur];
    for (int nbd: G[cur]) if(nbd!=par) 
        resCurNotHalved += dfs(G, memo, contrib, prices, nbd, cur, false);
    if (parHalved) return memo[cur][true] = resCurNotHalved;
    int resCurHalved = prices[cur]*contrib[cur]/2;
    for (int nbd: G[cur]) if(nbd!=par)
        resCurHalved += dfs(G, memo, contrib, prices, nbd, cur, true);
    return memo[cur][false] = min(resCurNotHalved, resCurHalved);
}

int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) 
{
    vector<vector<int>> G(n, vector<int>{});
    for (auto &edge: edges)
    {
        int u=edge[0], v=edge[1];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> contrib(n, 0);
    for (auto &trip: trips)
    {
        int src=trip[0], dest=trip[1];
        vector<int> path;
        getContrib(G, contrib, path, src, dest, -1);
    }
    vector<vector<int>> memo(n, vector<int>(2, -1));
    return dfs(G, memo, contrib, price, 0, -1, false);
}
 {% endhighlight %}
