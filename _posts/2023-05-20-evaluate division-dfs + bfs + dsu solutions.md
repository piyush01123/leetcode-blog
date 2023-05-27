---
layout: mypost
title: "Evaluate Division - DFS + BFS + DSU solutions"
tags: ["Array", "Depth-First Search", "Breadth-First Search", "Union Find", "Graph", "Shortest Path", "C++", "Medium"]
---
# Problem Statement:
<p>You are given an array of variable pairs <code>equations</code> and an array of real numbers <code>values</code>, where <code>equations[i] = [A<sub>i</sub>, B<sub>i</sub>]</code> and <code>values[i]</code> represent the equation <code>A<sub>i</sub> / B<sub>i</sub> = values[i]</code>. Each <code>A<sub>i</sub></code> or <code>B<sub>i</sub></code> is a string that represents a single variable.</p>

<p>You are also given some <code>queries</code>, where <code>queries[j] = [C<sub>j</sub>, D<sub>j</sub>]</code> represents the <code>j<sup>th</sup></code> query where you must find the answer for <code>C<sub>j</sub> / D<sub>j</sub> = ?</code>.</p>

<p>Return <em>the answers to all queries</em>. If a single answer cannot be determined, return <code>-1.0</code>.</p>

<p><strong>Note:</strong> The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> equations = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;c&quot;]], values = [2.0,3.0], queries = [[&quot;a&quot;,&quot;c&quot;],[&quot;b&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;e&quot;],[&quot;a&quot;,&quot;a&quot;],[&quot;x&quot;,&quot;x&quot;]]
<strong>Output:</strong> [6.00000,0.50000,-1.00000,1.00000,-1.00000]
<strong>Explanation:</strong> 
Given: <em>a / b = 2.0</em>, <em>b / c = 3.0</em>
queries are: <em>a / c = ?</em>, <em>b / a = ?</em>, <em>a / e = ?</em>, <em>a / a = ?</em>, <em>x / x = ?</em>
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> equations = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;c&quot;],[&quot;bc&quot;,&quot;cd&quot;]], values = [1.5,2.5,5.0], queries = [[&quot;a&quot;,&quot;c&quot;],[&quot;c&quot;,&quot;b&quot;],[&quot;bc&quot;,&quot;cd&quot;],[&quot;cd&quot;,&quot;bc&quot;]]
<strong>Output:</strong> [3.75000,0.40000,5.00000,0.20000]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> equations = [[&quot;a&quot;,&quot;b&quot;]], values = [0.5], queries = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;c&quot;],[&quot;x&quot;,&quot;y&quot;]]
<strong>Output:</strong> [0.50000,2.00000,-1.00000,-1.00000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= equations.length &lt;= 20</code></li>
	<li><code>equations[i].length == 2</code></li>
	<li><code>1 &lt;= A<sub>i</sub>.length, B<sub>i</sub>.length &lt;= 5</code></li>
	<li><code>values.length == equations.length</code></li>
	<li><code>0.0 &lt; values[i] &lt;= 20.0</code></li>
	<li><code>1 &lt;= queries.length &lt;= 20</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= C<sub>j</sub>.length, D<sub>j</sub>.length &lt;= 5</code></li>
	<li><code>A<sub>i</sub>, B<sub>i</sub>, C<sub>j</sub>, D<sub>j</sub></code> consist of lower case English letters and digits.</li>
</ul>

# Solution:
In BFS and DFS, the idea is to traverse the graph and at each node, keep track of the conversion factor. In DSU, the idea is to separately maintain the conversion factor with respect to the root for each node. What this means is that in DFS and BFS we will have to do traversal for each query separately, but in DSU, we can just look up the answer from a hashamp.

**DFS solution**:
 {% highlight cpp %} 
class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string,double>>>&G, unordered_set<string>&visited, \
                string source, string target, double factor)
    {
        if (source==target) return factor;
        for (auto &nbd: G[source]) if (!visited.count(nbd.first))
        {
            visited.insert(nbd.first);
            double res = dfs(G,visited,nbd.first,target,factor*nbd.second);
            if (res!=-1) return res;
        }
        return -1;
    }
    double solveQuery(unordered_map<string, vector<pair<string,double>>> &G, string c, string d)
    {
        unordered_set<string> visited;
        visited.insert(c);
        return dfs(G, visited, c, d, 1);
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n = equations.size();
        unordered_map<string, vector<pair<string,double>>> G;
        for (int i=0; i<n; i++)
        {
            string a=equations[i][0], b=equations[i][1];
            double v=values[i];
            G[a].push_back({b, v});
            G[b].push_back({a, 1/v});
        }
        vector<double> res(queries.size());
        for (int i=0; i<queries.size(); i++)
        {
            string c = queries[i][0], d=queries[i][1];
            if (!G.count(c) || !G.count(d)) res[i]=-1;
            else res[i] = solveQuery(G, queries[i][0], queries[i][1]);
        }            
        return res;
    }
};
 {% endhighlight %}
**BFS solution**:
 {% highlight cpp %} 
class Solution {
public:
    double solveQuery(unordered_map<string, vector<pair<string,double>>> &G, string c, string d)
    {
        queue<pair<string,double>>Q;
        unordered_set<string> visited;
        Q.push({c,1});
        visited.insert(c);
        while(!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                auto pair = Q.front();
                Q.pop();
                string cur=pair.first;
                double val=pair.second;
                if (cur==d) return val;
                for (auto nbd: G[cur]) if (!visited.count(nbd.first))
                {
                    if (nbd.first==d) return val*nbd.second;
                    visited.insert(nbd.first);
                    Q.push({nbd.first, val*nbd.second});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n = equations.size();
        unordered_map<string, vector<pair<string,double>>> G;
        for (int i=0; i<n; i++)
        {
            string a=equations[i][0], b=equations[i][1];
            double v=values[i];
            G[a].push_back({b, v});
            G[b].push_back({a, 1/v});
        }
        vector<double> res(queries.size());
        for (int i=0; i<queries.size(); i++)
        {
            string c = queries[i][0], d=queries[i][1];
            if (!G.count(c) || !G.count(d)) res[i]=-1;
            else res[i] = solveQuery(G, queries[i][0], queries[i][1]);
        }            
        return res;
    }
};
 {% endhighlight %}

**DSU solution**:
In the `find` opration, we return the conversion factor with respect to the root node along with the value of the root node. In the `union` operation, I am illustrating with an example. Let $x$ and $y$ be two nodes with roots $R_x$ and $R_y$ respectively. We have the conversion factors $x=r_1R_x$ and $y=r_2R_y$ with respect to the respective root nodes. Now we get the equation $x=ry$. We must set the conversion rate of $R_y$ wrt $R_x$ now. We have  $x=r_1R_x, y=r_2R_y, x=ry$.  We can solve to get $R_y = \frac{r_1}{rr_2}R_x$.

 {% highlight cpp %} 
class UnionFind
{
public:
    unordered_map<string, string> roots;
    unordered_map<string, int> ranks;
    unordered_map<string, double> rates;
    UnionFind(unordered_set<string> &nodes)
    {
        for (string node: nodes)
        {
            roots[node] = node;
            ranks[node] = 1;
            rates[node] = 1;
        }
    }
    void unionSet(string x, string y, double rate)
    {
        auto pairX = find(x), pairY = find(y);
        string rootX = pairX.first, rootY = pairY.first;
        double rateX = pairX.second, rateY = pairY.second;
        if (rootX==rootY) return;
        if (ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        if (ranks[rootX] <ranks[rootY])
        {
            swap(rootX, rootY);
            swap(rateX, rateY);
            rate = 1/rate;
        }
        roots[rootY] = rootX;
        //x=r1Rx, y=r2Ry, x=ry, r1Rx=r(r2Ry), Ry=(r1/(rr2))Rx
        rates[rootY] =  rateX / rateY / rate;
    }
    pair<string,double> find(string x)
    {
        if (x==roots[x]) return {x, rates[x]};
        auto pair = find(roots[x]);
        roots[x] = pair.first;
        rates[x] *= pair.second;
        return {roots[x], rates[x]};
    }
    double conversionFactor(string x, string y)
    {
        auto pairX = find(x), pairY = find(y);
        string rootX = pairX.first, rootY = pairY.first;
        double rateX = pairX.second, rateY = pairY.second;
        if (rootX!=rootY) return -1;
        return rateX/rateY;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, \
                                vector<vector<string>>& queries) 
    {
        unordered_set<string> nodes;
        for (auto &eqn: equations){nodes.insert(eqn[0]); nodes.insert(eqn[1]);}
        UnionFind uf = UnionFind(nodes);
        for (int i=0; i<equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            uf.unionSet(a, b, v);
        }
        vector<double> res;
        for (auto &query: queries)
        {
            string c = query[0], d=query[1];
            if (!nodes.count(c) || !nodes.count(d)) res.push_back(-1);
            else res.push_back(uf.conversionFactor(c, d));
        }
        return res;
    }
};
 {% endhighlight %}