---
layout: mypost
title: "Find All People With Secret - UnionFind and Min-Heap solutions"
tags: ["Depth-First Search", "Breadth-First Search", "Union Find", "Graph", "Sorting", "C++", "Heap (Priority Queue)", "Hard"]
---
# Problem Statement:
<p>You are given an integer <code>n</code> indicating there are <code>n</code> people numbered from <code>0</code> to <code>n - 1</code>. You are also given a <strong>0-indexed</strong> 2D integer array <code>meetings</code> where <code>meetings[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> indicates that person <code>x<sub>i</sub></code> and person <code>y<sub>i</sub></code> have a meeting at <code>time<sub>i</sub></code>. A person may attend <strong>multiple meetings</strong> at the same time. Finally, you are given an integer <code>firstPerson</code>.</p>

<p>Person <code>0</code> has a <strong>secret</strong> and initially shares the secret with a person <code>firstPerson</code> at time <code>0</code>. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person <code>x<sub>i</sub></code> has the secret at <code>time<sub>i</sub></code>, then they will share the secret with person <code>y<sub>i</sub></code>, and vice versa.</p>

<p>The secrets are shared <strong>instantaneously</strong>. That is, a person may receive the secret and share it with people in other meetings within the same time frame.</p>

<p>Return <em>a list of all the people that have the secret after all the meetings have taken place. </em>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3,5]
<strong>Explanation:
</strong>At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
<strong>Output:</strong> [0,1,3]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3,4]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i </sub>&lt;= n - 1</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= firstPerson &lt;= n - 1</code></li>
</ul>

# Solution:
We will discuss two approaches to the problem.

#### UnionFind solution
I hope you are already aware with the general setup of `UnionFind`. Basically it is the same as in following code except `reset` method has been introduced here.

`UnionFind` is a very useful strategy in problem where we have to find whether or not two nodes are connected or not, specially for a dynamic graph.

The crux of the logic is that first we create a data structure ` map<int, vector<pair<int,int>>>` named `H`. `H[t]` stores an array of all meetings occuring at time time `t`.  A. meeting is denoted by `pair<int,int>`. 

As we iterate through times in sorted order, we add each meeting to the `UnionFind` structure. However most crucially, **after all meetings are done for a time `t`, we reset the nodes which are not connected to node zero**. Thus, only nodes connected to node zero are prsent in the `UnionFind`. Once we are done with the meetings, we check which nodes are connected to node zero and that is our answer.

 {% highlight cpp %} 
class UnionFind
{public:
    vector<int> roots, ranks;
    UnionFind(int sz):roots(sz),ranks(sz,0){for(int i=0;i<sz;i++)roots[i]=i;}
    void unionSet(int u, int v)
    {
        u = find(u); v = find(v); 
        if(u==v) return;
        if(ranks[u]==ranks[v]) ranks[u]++;
        else if(ranks[u]<ranks[v]) swap(u,v);
        roots[v] = u;
    }
    int find(int u)
    {
        if(roots[u]==u) return u;
        return roots[u] = find(roots[u]);
    }
    void reset(int u){roots[u]=u;}
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        map<int, vector<pair<int,int>>> H;
        UnionFind uf(n);
        vector<int> res;
        uf.unionSet(0, firstPerson);
        for (auto &meet: meetings)
        {
            int x = meet[0], y = meet[1], time = meet[2];
            H[time].push_back({x,y});
        }
        for(auto &[_, meets]: H)
        {
            vector<int> people;
            for(auto &meet: meets)
            {
                int x= meet.first, y = meet.second;
                uf.unionSet(x,y);
                people.push_back(x); people.push_back(y);
            }
            for(int person: people) if(uf.find(person)!=uf.find(0)) uf.reset(person);
        }
        for(int i=0; i<n; i++)if(uf.find(i)==uf.find(0)) res.push_back(i);
        return res;
    }
};
 {% endhighlight %}
##### Min-Heap solution
This solution is based on processing nodes by time. Firstly we create a graph in adjacency list fashion. We have `pair<int,int>` which denotes secret knower and time of knowing the secret for the first time. We are going to build a min-heap of these pairs.

In the beginning, nodes zero and `firstPerson` are aded to the heap. Now, consider all people who know the secret to be part of `council`. As we iterate, people are popped out from the heap, we add them to the council and then check who all this guy is going to meet in future and add them to the  heap.

 {% highlight cpp %} 
#define pi pair<int,int>
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        vector<vector<pi>>G(n);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<bool> council(n, false);
        vector<int> res;
        for(auto &meeting: meetings)
        {
            int x = meeting[0], y = meeting[1], time = meeting[2];
            G[x].push_back({time,y});
            G[y].push_back({time,x});
        }
        pq.push({0, 0}); pq.push({0, firstPerson});
        while(!pq.empty())
        {
            auto p = pq.top(); pq.pop();
            int time = p.first, person = p.second;
            //  person alreaady knows secret,so his processing would be have been completed
            if(council[person]) continue; 
            // person now knows the secret
            council[person] = true; 
            // we now also have to include all the people he will meet in future
            for(auto &p: G[person])
            {
                int nextTime=p.first, nextPerson=p.second; 
                if(!council[nextPerson] && nextTime>=time)
                    pq.push(p);
            }
        }
        for(int i=0; i<n; i++) if(council[i]) res.push_back(i);
        return res;
    }
};
 {% endhighlight %}