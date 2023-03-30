---
layout: mypost
title: "Count Complete Tree Nodes - Recursivle solution with explanation"
tags: ["Binary Search", "Tree", "Depth-First Search", "Binary Tree", "C++", "Recursion", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a <strong>complete</strong> binary tree, return the number of the nodes in the tree.</p>

<p>According to <strong><a href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees" target="_blank">Wikipedia</a></strong>, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between <code>1</code> and <code>2<sup>h</sup></code> nodes inclusive at the last level <code>h</code>.</p>

<p>Design an algorithm that runs in less than&nbsp;<code data-stringify-type="code">O(n)</code>&nbsp;time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/complete.jpg" style="width: 372px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6]
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 5 * 10<sup>4</sup></code></li>
	<li>The tree is guaranteed to be <strong>complete</strong>.</li>
</ul>

# Solution:
First, let us define the concept of a "full" tree: a tree with no null nodes in the last level ie full upto its complete height.
(Consider height of root as 0, level 1 as 1 etc)
**IMP: What is the #(Nodes) in a full tree of height h**
Ans: `2^(h+1) - 1`

Now, given that we have "complete" tree of height `h`, we can say that either the left subtree is a "full" tree of height `h-1` or the right subtree is a "full" tree of height `h-2`. 

In the first case we have
 {% highlight cpp %} 
countNodes(root) = 2^h + countNodes(root->right)
 {% endhighlight %}
(`2^h = 2^h - 1` for left subtree and `1` for root)
and in the second case, we have

 {% highlight cpp %} 
countNodes(root) = 2^(h-1) + countNodes(root->left)
 {% endhighlight %}
(`2^(h-1) = 2^(h-1) - 1` for right subtree and `1` for root)

C++ code:
 {% highlight cpp %} 
class Solution {
public:
    int height(TreeNode *root)
    {
        return root == NULL ? -1 : 1+height(root->left);
    }
    int countNodes(TreeNode* root) 
    {
        if (!root) return 0;
        int h = height(root);
        if (h==0) return 1;
        if (height(root->right)==h-1)
            return (1<<h) + countNodes(root->right);
        else
            return (1<<h-1) + countNodes(root->left);
        return -1;
    }
};
 {% endhighlight %}
 {% highlight cpp %} 
TC=O((log n)^2)
 {% endhighlight %}
