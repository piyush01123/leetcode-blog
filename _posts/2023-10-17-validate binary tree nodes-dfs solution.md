---
layout: mypost
title: "Validate Binary Tree Nodes - DFS solution"
tags: ["Tree", "Depth-First Search", "Breadth-First Search", "Union Find", "Graph", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>You have <code>n</code> binary tree nodes numbered from <code>0</code> to <code>n - 1</code> where node <code>i</code> has two children <code>leftChild[i]</code> and <code>rightChild[i]</code>, return <code>true</code> if and only if <strong>all</strong> the given nodes form <strong>exactly one</strong> valid binary tree.</p>

<p>If node <code>i</code> has no left child then <code>leftChild[i]</code> will equal <code>-1</code>, similarly for the right child.</p>

<p>Note that the nodes have no values and that we only use the node numbers in this problem.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png" style="width: 195px; height: 287px;" />
<pre>
<strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex2.png" style="width: 183px; height: 272px;" />
<pre>
<strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex3.png" style="width: 82px; height: 174px;" />
<pre>
<strong>Input:</strong> n = 2, leftChild = [1,0], rightChild = [-1,-1]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == leftChild.length == rightChild.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-1 &lt;= leftChild[i], rightChild[i] &lt;= n - 1</code></li>
</ul>

# Solution:
One way to solve this is to find root and do a DFS traversal. If there is no root or if there are more than one roots, we can return `false` straight-away. Further, during the DFS traversal we check that we have not seen the current node earlier. For finding the root, we can use simple logic: Root is whichever node is never seen in either of the children arrays.

I thought this much is enough but there is a case where I got WA for one case:
 {% highlight cpp %} 
4
[1,0,3,-1]
[-1,-1,-1,-1]
 {% endhighlight %}
On checking you will see that we will need to add one more test to check that the tree rooted at the root we found indeed contains all the nodes from `0` to `n-1`, so we add a test to count all nodes at the end (`nodes.size()==n`).


 {% highlight cpp %} 
class Solution {
public:
    bool dfs(int root, vector<int>&lc, vector<int>&rc, unordered_set<int>&nodes)
    {
        if (root==-1) return true;
        if (nodes.count(root)) return false;
        nodes.insert(root);
        return dfs(lc[root], lc, rc, nodes) && dfs(rc[root], lc, rc, nodes);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        unordered_set<int> childrens;
        for (int i=0; i<n; i++){childrens.insert(leftChild[i]); childrens.insert(rightChild[i]);}
        childrens.erase(-1);
        if (childrens.size()!=n-1) return false;
        int root;
        for (int i=0; i<n; i++) if (!childrens.count(i)) root = i;
        unordered_set<int> nodes;
        return dfs(root, leftChild, rightChild, nodes) && nodes.size()==n;
    }
};
 {% endhighlight %}

An alternative solution to find root is by checking `inDegree` of each node. No node can have more than one `inDegree` and exactly one node must have zero `inDegree` which is the root. Again we will need to check the count of nodes.

 {% highlight cpp %} 
class Solution {
public:
    int count(int root, vector<int>&lc, vector<int>&rc)
    {
        if (root<0) return 0;
        return 1 + count(lc[root],lc,rc) + count(rc[root],lc,rc);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int> inDegree(n,0);
        for (int i=0;i<n;i++)
        {
            int lc = leftChild[i], rc=rightChild[i];
            if (lc>=0) if (inDegree[lc]) return false; else inDegree[lc]++;
            if (rc>=0) if (inDegree[rc]) return false; else inDegree[rc]++;
        }
        int root = -1;
        for (int i=0; i<n; i++) if (!inDegree[i]) if (root>=0) return false; else root = i;
        if (root<0) return false;
        return count(root,leftChild,rightChild)==n;
    }
};
 {% endhighlight %}

Both the solutions give us AC and are $O(n)$ in TC as well as SC.

Hope this helps!