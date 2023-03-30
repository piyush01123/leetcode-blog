---
layout: mypost
title: "Populating Next Right Pointers in Each Node - BFS+Queue O(1) space, O(n) time"
tags: ["Linked List", "Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>perfect binary tree</strong> where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:</p>

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
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="width: 500px; height: 171px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
<strong>Explanation: </strong>Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with &#39;#&#39; signifying the end of each level.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2<sup>12</sup> - 1]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.</li>
</ul>

# Solution:
We will use a queue. The children of the level nodes are stored in queue. Then one by one we go over the queue. 
# Puzzle
Note that we are iterating in the queue in reverse in the line         `for (int i=Q.size()-1; i>=0; --i)`. Can you tell why?

# Code: 
  {% highlight cpp %} 
Node* connect(Node* root) 
{
    if (!root) return NULL;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *curr=NULL, *prev=NULL;
        for (int i=Q.size()-1; i>=0; --i)
        {
            curr = Q.front();
            if (prev) prev->next = curr;
            Q.pop();
            if (curr->left) Q.push(curr->left);
            if (curr->right) Q.push(curr->right);
            prev = curr;
        }
        curr->next = NULL;
    }
    return root;
}
 {% endhighlight %}

Answer to puzzle is that because the queue size is increasing on the go, so we can not iterate forwards or else the loop will not end when we want it to end, so we must iterate in reverse.