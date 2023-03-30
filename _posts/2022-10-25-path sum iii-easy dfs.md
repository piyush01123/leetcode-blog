---
layout: mypost
title: "Path Sum III - Easy DFS"
tags: ["Tree", "Depth-First Search", "Binary Tree", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, return <em>the number of paths where the sum of the values&nbsp;along the path equals</em>&nbsp;<code>targetSum</code>.</p>

<p>The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg" style="width: 450px; height: 386px;" />
<pre>
<strong>Input:</strong> root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
<strong>Output:</strong> 3
<strong>Explanation:</strong> The paths that sum to 8 are shown.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 1000]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>

# Solution:
The idea is that any valid path will have a starting node and go down thereafter. So, we start from root and go down while checking if there is valid path starting from that node.
So, for the tree in the question example 1:
```
root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
```
We will check paths 
```
[10],[10,5],[10,5,3],[10,5,3,3],[10,5,3,-2],[10,5,2],[10,5,2,1],[10,-3],[10,-3,11]
```
Then we will check paths
```
[5],[5,3],[5,3,3],[5,3,-2],[5,2],[5,2,1]
```
and so on.

C++ code:
```
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        if (!root) return 0;
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int sumUp(TreeNode *root, long long curr, int target)
    {
        if (!root) return 0;
        curr += root->val;
        return (curr==target) + sumUp(root->left, curr, target) + sumUp(root->right,curr,target);
    }
};
```