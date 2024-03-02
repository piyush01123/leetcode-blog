---
layout: mypost
title: "Greatest Common Divisor Traversal - Prime graph connectivity"
tags: ["Array", "Math", "Union Find", "Number Theory", "C++", "Depth-First Search", "Hard"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>, and you are allowed to <strong>traverse</strong> between its indices. You can traverse between index <code>i</code> and index <code>j</code>, <code>i != j</code>, if and only if <code>gcd(nums[i], nums[j]) &gt; 1</code>, where <code>gcd</code> is the <strong>greatest common divisor</strong>.</p>

<p>Your task is to determine if for <strong>every pair</strong> of indices <code>i</code> and <code>j</code> in nums, where <code>i &lt; j</code>, there exists a <strong>sequence of traversals</strong> that can take us from <code>i</code> to <code>j</code>.</p>

<p>Return <code>true</code><em> if it is possible to traverse between all such pairs of indices,</em><em> or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,6]
<strong>Output:</strong> true
<strong>Explanation:</strong> In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -&gt; 2 -&gt; 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 &gt; 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 &gt; 1.
To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 &gt; 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 &gt; 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,9,5]
<strong>Output:</strong> false
<strong>Explanation:</strong> No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,3,12,8]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
The overall idea is that we enlist the prime factors of each number. Then, we create a graph of prime numbers where there is an edge between two prime numbers if they are prime factors of same number.

Once this graph is constructed, we need to find all prime numbers that can be used for checking inclusion. To do this, we can do `DFS` or `BFS` or `UnionFind`. Here I am giving example of `DFS` and `UnionFind`. Both solutions are accepted. We call these prime numbers as `goodPrimes`. Finally, we return `true` if `goodPrimes` encompasses all numbers ie for all numbers in input array `nums`, there is at least one good prime factor.

#### DFS Solution
 {% highlight cpp %} 
class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
    unordered_set<int> getPrimeFactors(int n)
    {
        unordered_set<int> factors;
        for(int i=2; i*i<=n; i++)
        {
            while(n%i==0)
            {
                factors.insert(i);
                n /= i;
            }
        }
        if(n>1) factors.insert(n); // Last prime factor is n
        return factors;
    }
    void dfs(int cur, int par)
    {
        if(visited[cur]) return;
        visited[cur] = true;
        for(int nbd: graph[cur]) if(nbd!=par) dfs(nbd,cur);
    }
    public: 
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        int n = nums.size(), ctr=0;
        if(n==1) return true;
        unordered_map<int,int> primeMap;
        vector<vector<int>> primeFactors(n);
        unordered_map<int,vector<int>> reversePrimeFactors;
        unordered_set<int> included, goodPrimes;
        for(int i=0; i<n; i++)
        {
            unordered_set<int> primes = getPrimeFactors(nums[i]);
            for(int p: primes)
            {
                primeFactors[i].push_back(p);
                reversePrimeFactors[p].push_back(i);
                if(!primeMap.count(p)) primeMap[p]=ctr++;
            }
        }
        if(ctr==0) return false;
        graph.resize(ctr);
        visited.resize(ctr,false);
        for(auto &v: primeFactors)
        {
            for(int p1:v) for(int p2:v)
            {
                if(p1==p2) continue;
                graph[primeMap[p1]].push_back(primeMap[p2]);
                graph[primeMap[p2]].push_back(primeMap[p1]);
            }
        }
        dfs(0,-1);
        for(auto &[p,i]: primeMap) if(visited[i]) goodPrimes.insert(p);
        for(int p: goodPrimes) for(int i: reversePrimeFactors[p]) included.insert(i);
        return included.size()==n;
    }
};
 {% endhighlight %}

#### UnionFind solution
 {% highlight cpp %} 
class UnionFind
{public:
    vector<int> roots, ranks;
    UnionFind(int sz):roots(sz),ranks(sz,1){for(int i=0;i<sz;i++)roots[i]=i;}
    void unionSet(int u, int v)
    {
        u = find(u); v = find(v);
        if(ranks[u]==ranks[v]) ranks[u]++;
        if(ranks[u]<ranks[v]) swap(u,v);
        roots[v] = u;
    }
    int find(int u)
    {
        if(roots[u]==u) return u;
        return roots[u] = find(roots[u]);
    }
};

class Solution {
    unordered_set<int> getPrimeFactors(int n)
    {
        unordered_set<int> factors;
        for(int i=2; i*i<=n; i++)
        {
            while(n%i==0)
            {
                factors.insert(i);
                n /= i;
            }
        }
        if(n>1) factors.insert(n); // Last prime factor is n
        return factors;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        int n = nums.size(), ctr=0;
        if(n==1) return true;
        unordered_map<int,int> primeMap;
        vector<vector<int>> primeFactors(n);
        unordered_map<int,vector<int>> reversePrimeFactors;
        unordered_set<int> included, goodPrimes;
        for(int i=0; i<n; i++)
        {
            unordered_set<int> primes = getPrimeFactors(nums[i]);
            for(int p: primes)
            {
                primeFactors[i].push_back(p);
                reversePrimeFactors[p].push_back(i);
                if(!primeMap.count(p)) primeMap[p]=ctr++;
            }
        }
        UnionFind uf = UnionFind(ctr);
        for(auto &v: primeFactors)
        {
            for(int p1:v) for(int p2:v)
            {
                if(p1==p2) continue;
                uf.unionSet(primeMap[p1],primeMap[p2]);
            }
        }
        for(auto &[p,i]: primeMap) if(uf.find(i)==uf.find(0)) goodPrimes.insert(p);
        for(int p: goodPrimes) for(int i: reversePrimeFactors[p]) included.insert(i);
        return included.size()==n;
    }
};
 {% endhighlight %}