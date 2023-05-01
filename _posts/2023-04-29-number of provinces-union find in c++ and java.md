---
layout: mypost
title: "Number of Provinces - Union Find in C++ and Java"
tags: ["Depth-First Search", "Breadth-First Search", "Union Find", "Graph", "C++", "Java", "Medium"]
---
# Problem Statement:
<p>There are <code>n</code> cities. Some of them are connected, while some are not. If city <code>a</code> is connected directly with city <code>b</code>, and city <code>b</code> is connected directly with city <code>c</code>, then city <code>a</code> is connected indirectly with city <code>c</code>.</p>

<p>A <strong>province</strong> is a group of directly or indirectly connected cities and no other cities outside of the group.</p>

<p>You are given an <code>n x n</code> matrix <code>isConnected</code> where <code>isConnected[i][j] = 1</code> if the <code>i<sup>th</sup></code> city and the <code>j<sup>th</sup></code> city are directly connected, and <code>isConnected[i][j] = 0</code> otherwise.</p>

<p>Return <em>the total number of <strong>provinces</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>Input:</strong> isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>Input:</strong> isConnected = [[1,0,0],[0,1,0],[0,0,1]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n == isConnected.length</code></li>
	<li><code>n == isConnected[i].length</code></li>
	<li><code>isConnected[i][j]</code> is <code>1</code> or <code>0</code>.</li>
	<li><code>isConnected[i][i] == 1</code></li>
	<li><code>isConnected[i][j] == isConnected[j][i]</code></li>
</ul>

# Solution:
**C++ solution**:
 {% highlight java %} 
class UnionFind
{
    vector<int> roots;
    vector<int> ranks;
public: 
    UnionFind(int sz)
    {
        roots = vector<int>(sz);
        ranks = vector<int>(sz);
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=1;}
    }
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return;
        if (ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        if (ranks[rootX]<ranks[rootY]) swap(rootX,rootY);
        roots[rootY] = rootX;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    int numGroups(int sz)
    {
        unordered_set<int> mySet;
        for (int i=0; i<sz; i++) mySet.insert(find(i));
        return mySet.size();
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(isConnected[i][j])
            uf.unionSet(i,j);
        return uf.numGroups(n);
    }
};
 {% endhighlight %}
**Java solution**:
 {% highlight java %} 
class UnionFind
{
    int[] roots;
    int[] ranks;
    public UnionFind(int sz)
    {
        roots = new int[sz];
        ranks = new int[sz];
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=0;}
    }
    public int unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return 0;
        if (ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        if (ranks[rootX]< ranks[rootY]) 
            {int temp=rootX; rootX=rootY; rootY=temp;}
        roots[rootY] = rootX;
        return 1;
    }
    public int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    public int numGroups(int sz)
    {
        HashSet<Integer> mySet = new HashSet<Integer>();
        for (int i=0; i<sz; i++) mySet.add(find(i));
        return mySet.size();
    }
}


class Solution 
{
    public int findCircleNum(int[][] isConnected) 
    {
        int n=isConnected.length;
        UnionFind uf = new UnionFind(n);
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(isConnected[i][j]==1)
            uf.unionSet(i,j);
        return uf.numGroups(n);
    }
}
 {% endhighlight %}