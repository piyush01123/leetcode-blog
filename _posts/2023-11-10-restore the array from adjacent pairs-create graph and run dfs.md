---
layout: mypost
title: "Restore the Array From Adjacent Pairs - Create graph and run DFS"
tags: ["Array", "Hash Table", "C++", "Java", "Depth-First Search", "Medium"]
---
# Problem Statement:
<p>There is an integer array <code>nums</code> that consists of <code>n</code> <strong>unique </strong>elements, but you have forgotten it. However, you do remember every pair of adjacent elements in <code>nums</code>.</p>

<p>You are given a 2D integer array <code>adjacentPairs</code> of size <code>n - 1</code> where each <code>adjacentPairs[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates that the elements <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> are adjacent in <code>nums</code>.</p>

<p>It is guaranteed that every adjacent pair of elements <code>nums[i]</code> and <code>nums[i+1]</code> will exist in <code>adjacentPairs</code>, either as <code>[nums[i], nums[i+1]]</code> or <code>[nums[i+1], nums[i]]</code>. The pairs can appear <strong>in any order</strong>.</p>

<p>Return <em>the original array </em><code>nums</code><em>. If there are multiple solutions, return <strong>any of them</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> adjacentPairs = [[2,1],[3,4],[3,2]]
<strong>Output:</strong> [1,2,3,4]
<strong>Explanation:</strong> This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> adjacentPairs = [[4,-2],[1,4],[-3,1]]
<strong>Output:</strong> [-2,4,1,-3]
<strong>Explanation:</strong> There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> adjacentPairs = [[100000,-100000]]
<strong>Output:</strong> [100000,-100000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>adjacentPairs.length == n - 1</code></li>
	<li><code>adjacentPairs[i].length == 2</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i], u<sub>i</sub>, v<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li>There exists some <code>nums</code> that has <code>adjacentPairs</code> as its pairs.</li>
</ul>

# Solution:
We can create an adjacency list by iterating over all `adjacentPairs`. This represents a graph with structure like an array ie two nodes (left and right ends) have one neighbor whereas the rest have two neighbors each.
We can run DFS from one of the terminal nodes to get all nodes of graph in the order in which they appear in the original array.

 {% highlight java %} 
class Solution {
    vector<int>res;
public:
    void dfs(unordered_map<int,vector<int>> &G, int cur, int par)
    {
        res.push_back(cur);
        for (int ch: G[cur])if(ch!=par) dfs(G,ch,cur);
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int,vector<int>> G;
        for(auto &v: adjacentPairs)
        {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        int cur;
        for(auto &[k,v]:G)if(v.size()==1) {cur=k;break;}
        dfs(G,cur,-1);
        return res;
    }
};
 {% endhighlight %}

SOLUTION II:
---

Since we already know the graph structure, we can also do the traversal in the following way:

We find out the `start` and `end` nodes. We initialize `cur` with `start` and iterate till `cur` is same as `end`.

 {% highlight java %} 
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int,vector<int>> G;
        for(auto &v: adjacentPairs)
        {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        int start=-1,end=-1;
        for(auto &[k,v]:G)if(v.size()==1)if(start!=-1){end=k;break;}else start=k;
        int cur=start,prev=-1;
        vector<int> res {start};
        while(cur!=end)
        {
            for (int next: G[cur]) if(next==prev) continue; 
            else {prev=cur; cur=next; break;}
            res.push_back(cur);
        }
        return res;
    }
};
 {% endhighlight %}

Java solution
---
 {% highlight java %} 
class Solution {
    void dfs(Map<Integer, List<Integer>> H, int[]res, int cur, int index, int par)
    {
        res[index] = cur;
        for (int ch: H.get(cur)) if (ch==par) continue; else dfs(H,res,ch,index+1,cur);
    }
    public int[] restoreArray(int[][] adjacentPairs) 
    {
        Map<Integer, List<Integer>> H = new HashMap();
        for (int[] pair: adjacentPairs)
        {
            H.computeIfAbsent(pair[0], k->new ArrayList()).add(pair[1]);
            H.computeIfAbsent(pair[1], k->new ArrayList()).add(pair[0]);
        }
        int cur=-1;
        for(var entry: H.entrySet())if(entry.getValue().size()==1)
                                    {cur=entry.getKey();break;}
        int[] res = new int[adjacentPairs.length + 1];
        dfs(H,res,cur,0,-1);
        return res;
    }
}
 {% endhighlight %}
 {% highlight java %} 
class Solution {
    public int[] restoreArray(int[][] adjacentPairs) 
    {
        Map<Integer, List<Integer>> H = new HashMap();
        for (int[] pair: adjacentPairs)
        {
            H.computeIfAbsent(pair[0], k->new ArrayList()).add(pair[1]);
            H.computeIfAbsent(pair[1], k->new ArrayList()).add(pair[0]);
        }
        int start=-1, end=-1;
        for(var entry: H.entrySet())if(entry.getValue().size()==1)
        if(start!=-1){end=entry.getKey();break;} else start=entry.getKey();
        int[] res = new int[adjacentPairs.length + 1];
        res[0] = start;
        int cur = start, i=0, prev=-1;
        while(cur!=end)
        {
            for (int ch: H.get(cur)) if (ch==prev) continue;
            else {prev=cur; cur=ch; break;}
            res[++i] = cur;
        }
        return res;
    }
}
 {% endhighlight %}