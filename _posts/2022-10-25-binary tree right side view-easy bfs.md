---
layout: mypost
title: "Binary Tree Right Side View - Easy BFS"
tags: ["Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, imagine yourself standing on the <strong>right side</strong> of it, return <em>the values of the nodes you can see ordered from top to bottom</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/14/tree.jpg" style="width: 401px; height: 301px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,null,5,null,4]
<strong>Output:</strong> [1,3,4]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,null,3]
<strong>Output:</strong> [1,3]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

# Solution:
```
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};
        vector<int>res;
        queue<TreeNode *>Q;
        Q.push(root);
        while (!Q.empty())
        {
            int qsize = Q.size();
            for (int i=0; i<qsize; i++)
            {
                root = Q.front();
                Q.pop();
                if (root->left) Q.push(root->left);
                if(root->right) Q.push(root->right);
            }
            res.push_back(root->val);
        }
        return res;
    }
};
```