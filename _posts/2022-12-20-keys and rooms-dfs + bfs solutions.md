---
layout: mypost
title: "Keys and Rooms - DFS + BFS solutions"
tags: ["Depth-First Search", "Breadth-First Search", "Graph", "C++", "Medium"]
---
# Problem Statement:
<p>There are <code>n</code> rooms labeled from <code>0</code> to <code>n - 1</code>&nbsp;and all the rooms are locked except for room <code>0</code>. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.</p>

<p>When you visit a room, you may find a set of <strong>distinct keys</strong> in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.</p>

<p>Given an array <code>rooms</code> where <code>rooms[i]</code> is the set of keys that you can obtain if you visited room <code>i</code>, return <code>true</code> <em>if you can visit <strong>all</strong> the rooms, or</em> <code>false</code> <em>otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> rooms = [[1],[2],[3],[]]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> rooms = [[1,3],[3,0,1],[2],[0]]
<strong>Output:</strong> false
<strong>Explanation:</strong> We can not enter room number 2 since the only key that unlocks it is in that room.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == rooms.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= rooms[i].length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(rooms[i].length) &lt;= 3000</code></li>
	<li><code>0 &lt;= rooms[i][j] &lt; n</code></li>
	<li>All the values of <code>rooms[i]</code> are <strong>unique</strong>.</li>
</ul>

# Solution:
# Intuition
This is a straightforward graph traversal problem.
# Approach
We can do a simple BFS or DFS traversal to solve this.
# Complexity
- Time complexity:
O(V) where V is the number of rooms
- Space complexity:
O(V) where V is the number of rooms
# Code
## BFS solution
 {% highlight cpp %} 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited = vector<bool>(n,false);
        queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                int cur = Q.front();
                Q.pop();
                visited[cur] = true;
                for (int adj: rooms[cur]) if (!visited[adj]) Q.push(adj);
            }
        }
        for (bool v: visited) if (!v) return false;
        return true;
    }
};
 {% endhighlight %}
## DFS solution
 {% highlight cpp %} 
class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<bool>&visited, int u)
    {
        visited[u] = true;
        for (int v: rooms[u]) if (!visited[v]) dfs(rooms,visited,v);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited = vector<bool>(n,false);
        dfs(rooms, visited, 0);
        for (bool v: visited) if (!v) return false;
        return true;
    }
};
 {% endhighlight %}