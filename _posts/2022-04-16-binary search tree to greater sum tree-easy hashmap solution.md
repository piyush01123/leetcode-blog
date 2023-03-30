---
layout: mypost
title: "Binary Search Tree to Greater Sum Tree - Easy HashMap solution"
tags: ["Tree", "Depth-First Search", "Binary Search Tree", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.</p>

<p>As a reminder, a <em>binary search tree</em> is a tree that satisfies these constraints:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node&#39;s key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node&#39;s key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/02/tree.png" style="width: 400px; height: 273px;" />
<pre>
<strong>Input:</strong> root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong>Output:</strong> [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [0,null,1]
<strong>Output:</strong> [1,null,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li>All the values in the tree are <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 538: <a href="https://leetcode.com/problems/convert-bst-to-greater-tree/" target="_blank">https://leetcode.com/problems/convert-bst-to-greater-tree/</a></p>

# Solution:
Given that all keys in the tree are unique we can use a HashMap of the structure `unordered_map<int,TreeNode*>` to store the tree. Then we can do the operations asked and substitute appropriate values as the new keys.
 {% highlight cpp %} 
class Solution {
public:
    void traverse(TreeNode *root, unordered_map<int, TreeNode *>&H)
    {
        if (root==NULL) return;
        H[root->val] = root;
        traverse(root->left, H);
        traverse(root->right, H);
    }
    TreeNode* bstToGst(TreeNode* root) {
        unordered_map<int, TreeNode *> H;
        traverse(root, H);
        vector<int> v1, v2;
        for (auto item: H) v1.push_back(item.first);
        sort(v1.begin(),v1.end(), greater<int>());
        int curr=0;
        for (int i: v1)
        {
            v2.push_back(curr+i);
            curr+=i;
        }
        for (int i=0; i<v1.size(); i++) H[v1[i]]->val = v2[i];
        return root;
    }
};
 {% endhighlight %}