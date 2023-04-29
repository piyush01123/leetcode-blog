---
layout: mypost
title: "Checking Existence of Edge Length Limited Paths - Union-Find with sorted edges and queries"
tags: ["Array", "Union Find", "Graph", "Sorting", "C++", "Java", "Sort", "Hard"]
---
# Problem Statement:
<p>An undirected graph of <code>n</code> nodes is defined by <code>edgeList</code>, where <code>edgeList[i] = [u<sub>i</sub>, v<sub>i</sub>, dis<sub>i</sub>]</code> denotes an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with distance <code>dis<sub>i</sub></code>. Note that there may be <strong>multiple</strong> edges between two nodes.</p>

<p>Given an array <code>queries</code>, where <code>queries[j] = [p<sub>j</sub>, q<sub>j</sub>, limit<sub>j</sub>]</code>, your task is to determine for each <code>queries[j]</code> whether there is a path between <code>p<sub>j</sub></code> and <code>q<sub>j</sub></code><sub> </sub>such that each edge on the path has a distance <strong>strictly less than</strong> <code>limit<sub>j</sub></code> .</p>

<p>Return <em>a <strong>boolean array</strong> </em><code>answer</code><em>, where </em><code>answer.length == queries.length</code> <em>and the </em><code>j<sup>th</sup></code> <em>value of </em><code>answer</code> <em>is </em><code>true</code><em> if there is a path for </em><code>queries[j]</code><em> is </em><code>true</code><em>, and </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/08/h.png" style="width: 267px; height: 262px;" />
<pre>
<strong>Input:</strong> n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
<strong>Output:</strong> [false,true]
<strong>Explanation:</strong> The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -&gt; 1 -&gt; 2) of two edges with distances less than 5, thus we return true for this query.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/08/q.png" style="width: 390px; height: 358px;" />
<pre>
<strong>Input:</strong> n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
<strong>Output:</strong> [true,false]
<strong>Exaplanation:</strong> The above figure shows the given graph.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= edgeList.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edgeList[i].length == 3</code></li>
	<li><code>queries[j].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub>, p<sub>j</sub>, q<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>p<sub>j</sub> != q<sub>j</sub></code></li>
	<li><code>1 &lt;= dis<sub>i</sub>, limit<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li>There may be <strong>multiple</strong> edges between two nodes.</li>
</ul>

# Solution:
The idea is to pre-sort the edges by their lengths and queries by their limits. Then, for any given query we will have some set of edges. Notice that as we traverse query after query, this set of edges can only get larger as limit for edge length increases. For each query, we use the Union-Find data structure at that point to find whether the nodes in query are connected or not with the valid edges at that point. This gives us the answer for that query.

**C++ code**:
 {% highlight java %} 
class UnionFind {
public:
    UnionFind(int sz) : roots(sz), ranks(sz) 
    {
        for (int i = 0; i < sz; ++i) {roots[i] = i; ranks[i]=0;}
    }
    int find(int x) 
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    void unionSet(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if(ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        else if (ranks[rootX]<ranks[rootY]) swap(rootY,rootX);
        roots[rootY] = rootX;
    }
    bool isConnected(int x, int y)
    {
      return (find(x)==find(y));
    }
private:
    vector<int> roots;
    vector<int> ranks;
};



class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        auto cmp = [](const vector<int>&veca, const vector<int>&vecb){return veca[2]<vecb[2];};
        sort(edgeList.begin(), edgeList.end(), cmp);
        for(int i=0; i<queries.size(); i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);

        UnionFind uf = UnionFind(n);
        vector<bool>res(queries.size());
        int edgeIdx = 0;
        for (auto &query: queries)
        {
            int p=query[0], q=query[1], limit=query[2], qIdx=query[3];
            while (edgeIdx<edgeList.size()) 
            {
                int u=edgeList[edgeIdx][0], v=edgeList[edgeIdx][1], dis=edgeList[edgeIdx][2];
                if (dis>=limit) break;
                uf.unionSet(u, v);
                edgeIdx++;
            }
            res[qIdx] = uf.isConnected(p,q);
        }
        return res;
    }
};
 {% endhighlight %}
**Java code**:
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
    public void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return;
        if (ranks[rootX]<ranks[rootY]){int temp=rootX;rootX=rootY;rootY=temp;}
        roots[rootY] = rootX;
    }
    public int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    public boolean isConnected(int x, int y)
    {
        return (find(x)==find(y));
    }
}


class Solution {
    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) 
    {
        Arrays.sort(edgeList, (veca,vecb)->veca[2]-vecb[2]);
        for (int i=0; i<queries.length; i++)
        {
            int[] row = queries[i]; queries[i] = new int[4];
            for(int j=0;j<3;j++)queries[i][j]=row[j];queries[i][3]=i;
        }
        Arrays.sort(queries, (veca,vecb)->veca[2]-vecb[2]);

        UnionFind uf = new UnionFind(n);
        boolean[] res = new boolean[queries.length];
        int edgeIdx = 0;
        for (int[] query: queries)
        {
            int p=query[0], q=query[1], limit=query[2], qIdx=query[3];
            while (edgeIdx<edgeList.length) 
            {
                int u=edgeList[edgeIdx][0], v=edgeList[edgeIdx][1], dis=edgeList[edgeIdx][2];
                if (dis>=limit) break;
                uf.unionSet(u, v);
                edgeIdx++;
            }
            res[qIdx] = uf.isConnected(p,q);
        }
        return res;
    }
}
 {% endhighlight %}