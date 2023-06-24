---
layout: mypost
title: "Unique Binary Search Trees II - Recursion and memoization DP"
tags: ["Dynamic Programming", "Backtracking", "Tree", "Binary Search Tree", "Binary Tree", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>Given an integer <code>n</code>, return <em>all the structurally unique <strong>BST&#39;</strong>s (binary search trees), which has exactly </em><code>n</code><em> nodes of unique values from</em> <code>1</code> <em>to</em> <code>n</code>. Return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

# Solution:
We have the following recursive relation:

$$T(s,e) = \{ TreeNode(v=i,L=ta,R=tb) \forall ta \in T(s,i-1), tb \in  T(i+1,e) \} $$

where $T(a,b)$ denotes answer for array containing BSTs containing values from $a$ to $b$. Our final answer is $T(1,n)$.

We will have repetition so let us add memoization. We will need 3-d array for memoization. Two indexes for $s, e$ and one for the array of treenodes $T(s,e)$.
 {% highlight cpp %} 
class Solution {
    vector<vector<vector<TreeNode*>>> memo = vector<vector<vector<TreeNode*>>>(9, vector<vector<TreeNode*>>(9));
public:
    vector<TreeNode*> generateTrees(int n, int s=1) 
    {
        if (s>n || s<=0) return {NULL};
        if (memo[s][n].size()>0) return memo[s][n];
        if (s==n) return memo[s][n] = {new TreeNode(n)};
        vector<TreeNode*> res;
        for(int i=s; i<=n; i++)
        {
            vector<TreeNode*> leftTrees = generateTrees(i-1,s);
            vector<TreeNode*> rightTrees = generateTrees(n, i+1);
            for(TreeNode *left: leftTrees) for(TreeNode *right: rightTrees)
                res.push_back(new TreeNode(i, left, right));
        }
        return memo[s][n] = res;
    }
};
 {% endhighlight %}