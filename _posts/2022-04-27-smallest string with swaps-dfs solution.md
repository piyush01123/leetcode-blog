---
layout: mypost
title: "Smallest String With Swaps - DFS solution"
tags: ["Hash Table", "String", "Depth-First Search", "Breadth-First Search", "Union Find", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a string <code>s</code>, and an array of pairs of indices in the string&nbsp;<code>pairs</code>&nbsp;where&nbsp;<code>pairs[i] =&nbsp;[a, b]</code>&nbsp;indicates 2 indices(0-indexed) of the string.</p>

<p>You can&nbsp;swap the characters at any pair of indices in the given&nbsp;<code>pairs</code>&nbsp;<strong>any number of times</strong>.</p>

<p>Return the&nbsp;lexicographically smallest string that <code>s</code>&nbsp;can be changed to after using the swaps.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;dcab&quot;, pairs = [[0,3],[1,2]]
<strong>Output:</strong> &quot;bacd&quot;
<strong>Explaination:</strong> 
Swap s[0] and s[3], s = &quot;bcad&quot;
Swap s[1] and s[2], s = &quot;bacd&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;dcab&quot;, pairs = [[0,3],[1,2],[0,2]]
<strong>Output:</strong> &quot;abcd&quot;
<strong>Explaination: </strong>
Swap s[0] and s[3], s = &quot;bcad&quot;
Swap s[0] and s[2], s = &quot;acbd&quot;
Swap s[1] and s[2], s = &quot;abcd&quot;</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cba&quot;, pairs = [[0,1],[1,2]]
<strong>Output:</strong> &quot;abc&quot;
<strong>Explaination: </strong>
Swap s[0] and s[1], s = &quot;bca&quot;
Swap s[1] and s[2], s = &quot;bac&quot;
Swap s[0] and s[1], s = &quot;abc&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs[i][0], pairs[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>s</code>&nbsp;only contains lower case English letters.</li>
</ul>

# Solution:
- Create graph using `pairs` as adjancency list.
- Start with a node. Do DFS traversal. Sort the node ids (string indices) and characters both. Then put the characters in order.
- Repeat for all nodes. Do not do for already visited nodes.

 {% highlight cpp %} 
class Solution {
public:
    int n;
    vector<vector<int>> edges;
    vector<bool> visited;
    
    void DFS(int src, vector<int>&visited_nodes)
    {
        visited[src]=true;
        visited_nodes.push_back(src);
        for (int dest: edges[src])
            if (!visited[dest]) DFS(dest, visited_nodes);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        n = s.size();
        edges =  vector<vector<int>>(n, vector<int>{});
        for (auto p: pairs)
        {
            int u=p[0], v=p[1];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        visited = vector<bool>(n, false);
        for (int u=0; u<n; u++)
        {
            if (!visited[u])
            {
                vector<int> visited_nodes;
                DFS(u, visited_nodes);
                vector<char> visited_chars;
                for (int i: visited_nodes) visited_chars.push_back(s[i]);
                sort(visited_chars.begin(), visited_chars.end());
                sort(visited_nodes.begin(), visited_nodes.end());
                for (int i=0; i<visited_nodes.size(); i++)
                    s[visited_nodes[i]]=visited_chars[i];
            }
        }
        return s;
    }
};
 {% endhighlight %}