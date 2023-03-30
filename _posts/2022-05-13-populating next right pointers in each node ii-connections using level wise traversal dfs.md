---
layout: mypost
title: "Populating Next Right Pointers in Each Node II - Connections using Level Wise Traversal DFS"
tags: ["Linked List", "Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given a binary tree</p>

<pre>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre>

<p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>

<p>Initially, all next pointers are set to <code>NULL</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/15/117_sample.png" style="width: 500px; height: 171px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,null,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,7,#]
<strong>Explanation: </strong>Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with &#39;#&#39; signifying the end of each level.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 6000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.</li>
</ul>

# Solution:
If you do not know [level order traversal problem](https://leetcode.com/problems/binary-tree-level-order-traversal/), refere here:
[Level Order Traversal - Two DFS solutions](https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/2034163/Two-DFS-solutions)
<br>
Now we can immediately think of a solution:
Instead of storing the keys, sotre the node pointers and then make required connections.
 {% highlight cpp %} 
class Solution {
public:
    void dfs(Node *root, vector<vector<Node *>> &lvn, int level)
    {
        if (!root) return;
        if (level==lvn.size()) lvn.push_back({});
        lvn[level].push_back(root);
        dfs(root->left, lvn, level+1);
        dfs(root->right, lvn, level+1);
    }
    Node* connect(Node* root) {
        vector<vector<Node *>> levelWiseNodes;
        dfs(root, levelWiseNodes, 0);
        for (int i=0; i<levelWiseNodes.size(); i++)
        {
            if (levelWiseNodes[i].size()<2) continue;
            for (int j=0; j<=levelWiseNodes[i].size()-2; j++)
            {
               levelWiseNodes[i][j]->next = levelWiseNodes[i][j+1];
            }
        }
        return root;
    }
};
 {% endhighlight %}
