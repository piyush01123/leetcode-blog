---
layout: mypost
title: "Similar String Groups - DFS + BFS + Union-Find solutions"
tags: ["Array", "String", "Depth-First Search", "Breadth-First Search", "Union Find", "C++", "Hard"]
---
# Problem Statement:
<p>Two strings <code>X</code>&nbsp;and <code>Y</code>&nbsp;are similar if we can swap two letters (in different positions) of <code>X</code>, so that&nbsp;it equals <code>Y</code>. Also two strings <code>X</code> and <code>Y</code> are similar if they are equal.</p>

<p>For example, <code>&quot;tars&quot;</code>&nbsp;and <code>&quot;rats&quot;</code>&nbsp;are similar (swapping at positions <code>0</code> and <code>2</code>), and <code>&quot;rats&quot;</code> and <code>&quot;arts&quot;</code> are similar, but <code>&quot;star&quot;</code> is not similar to <code>&quot;tars&quot;</code>, <code>&quot;rats&quot;</code>, or <code>&quot;arts&quot;</code>.</p>

<p>Together, these form two connected groups by similarity: <code>{&quot;tars&quot;, &quot;rats&quot;, &quot;arts&quot;}</code> and <code>{&quot;star&quot;}</code>.&nbsp; Notice that <code>&quot;tars&quot;</code> and <code>&quot;arts&quot;</code> are in the same group even though they are not similar.&nbsp; Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.</p>

<p>We are given a list <code>strs</code> of strings where every string in <code>strs</code> is an anagram of every other string in <code>strs</code>. How many groups are there?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;tars&quot;,&quot;rats&quot;,&quot;arts&quot;,&quot;star&quot;]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;omv&quot;,&quot;ovm&quot;]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 300</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 300</code></li>
	<li><code>strs[i]</code> consists of lowercase letters only.</li>
	<li>All words in <code>strs</code> have the same length and are anagrams of each other.</li>
</ul>

# Solution:
**Notion of similarity**: Two strings are similar if they differ at exactly 0 or 2 positions. This is because we are given that all strings are anagrams of each other, so 0 swaps means differ at 0 positions and 1 swap means differ at exactly 2 positions.

We can now create a graph where each string in `strs` is a node in the graph and two nodes are connected if they are similar strings as defined above.

**DFS solution**: We run DFS for each unvisited node. Number of times we have to start DFS is the answer.

 {% highlight cpp %} 
class Solution {
public:
    void dfs(vector<vector<int>>&G, vector<bool>&visited, int cur)
    {
        visited[cur] = true;
        for (int nbd: G[cur]) if (!visited[nbd]) dfs(G, visited, nbd);
    }
    bool isSimilar(string s1, string s2)
    {
        int diff=0;
        for (int i=0; i<s1.length(); i++) if (s1[i]!=s2[i]) if(++diff>2) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size(), res=0;
        vector<vector<int>> G(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(isSimilar(strs[i],strs[j]))
        {
            G[i].push_back(j);
            G[j].push_back(i);
        }
        vector<bool>visited(n,false);
        for (int i=0; i<n; i++) if(!visited[i]) 
        {
            dfs(G,visited,i);
            res++;
        }
        return res;
    }
};
 {% endhighlight %}

**BFS solution**: Same thing can be done using a queue in a BFS.

 {% highlight cpp %} 
class Solution {
public:
    void bfs(vector<vector<int>>&G, vector<bool>&visited, int cur)
    {
        queue<int>Q;
        Q.push(cur);
        visited[cur] = true;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (int nbd: G[node]) if(!visited[nbd])
            {
                Q.push(nbd);
                visited[nbd] = true;
            }
        }
    }
    bool isSimilar(string s1, string s2)
    {
        int diff=0;
        for (int i=0; i<s1.length(); i++) if (s1[i]!=s2[i]) if(++diff>2) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size(), res=0;
        vector<vector<int>> G(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(isSimilar(strs[i],strs[j]))
        {
            G[i].push_back(j);
            G[j].push_back(i);
        }
        vector<bool>visited(n,false);
        for (int i=0; i<n; i++) if(!visited[i]) 
        {
            bfs(G,visited,i);
            res++;
        }
        return res;
    }
};
 {% endhighlight %}

**Union-Find solution or Disjoint-Set-Union (DSU) solution**: We can also create a Union-Find data structure where we create union for each pair of similar words. Read more on Union-Find in [this LC explore card](https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3840/). Here we will use an optimized implementation of Union-Find with path compression and union by rank. Finally the number of unique root nodes in the UF data structure is the answer.

 {% highlight cpp %} 
class UnionFind {
public:
    UnionFind(int sz) : root(sz), ranks(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            ranks[i] = 1;
        }
    }
    int find(int x) {
        if (x==root[x]) return x;
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if(ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        else if (ranks[rootX]<ranks[rootY]) swap(rootY,rootX);
        root[rootY] = rootX;
    }
private:
    vector<int> root;
    vector<int> ranks;
};

class Solution {
public:
    bool isSimilar(string s1, string s2)
    {
        int diff=0;
        for (int i=0; i<s1.length(); i++) if (s1[i]!=s2[i]) if(++diff>2) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        UnionFind uf = UnionFind(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) 
        if(isSimilar(strs[i],strs[j])) uf.unionSet(i, j);
        unordered_set<int> myset;
        for(int i=0; i<n; i++) myset.insert(uf.find(i));
        return myset.size();
    }
};
 {% endhighlight %}

All three solutions have TC of $O(n^2 \vert s \vert)$ and SC of DFS and BFS solutions is $O(n^2)$ (to store the graph) whereas SC of Union-Find solution is $O(n)$.