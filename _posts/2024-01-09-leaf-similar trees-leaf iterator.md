---
layout: mypost
title: "Leaf-Similar Trees - Leaf Iterator"
tags: ["Tree", "Depth-First Search", "Binary Tree", "C++", "Iterator", "Easy"]
---
# Problem Statement:
<p>Consider all the leaves of a binary tree, from&nbsp;left to right order, the values of those&nbsp;leaves form a <strong>leaf value sequence</strong><em>.</em></p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png" style="width: 400px; height: 336px;" /></p>

<p>For example, in the given tree above, the leaf value sequence is <code>(6, 7, 4, 9, 8)</code>.</p>

<p>Two binary trees are considered <em>leaf-similar</em>&nbsp;if their leaf value sequence is the same.</p>

<p>Return <code>true</code> if and only if the two given trees with head nodes <code>root1</code> and <code>root2</code> are leaf-similar.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg" style="width: 600px; height: 237px;" />
<pre>
<strong>Input:</strong> root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg" style="width: 300px; height: 110px;" />
<pre>
<strong>Input:</strong> root1 = [1,2,3], root2 = [1,3,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each tree will be in the range <code>[1, 200]</code>.</li>
	<li>Both of the given trees will have values in the range <code>[0, 200]</code>.</li>
</ul>

# Solution:

Hopefully you have already solved this problem by DFS or BFS method. I will not go there. I think this could be a new unseen problem to create a `LeafIterator` that returns the next leaf node value. A similar problem is `BSTIterator` [present here](https://leetcode.com/problems/binary-search-tree-iterator/). This could be a medium problem.

We use a similar method to build `LeafIterator` and we are able to do it in `O(h)` space where `h` equals the height of tree. The only change is that instead of the next inorder traversal value we return only if the current node is a leaf node. We will have to separately handle the case when the inorder traversal does not end at a leaf node and we will return `-1` in that case. Return value of -1 from `next()` indicates that there are no more nodes similar to `hasNext()` returning `false`.

 {% highlight cpp %} 
class LeafIterator
{public:
    stack<TreeNode*> stk;
    LeafIterator(TreeNode *root)
    {
        goLeft(root);
    }
    int next()
    {
        if (!hasNext()) return -1;
        TreeNode* cur = stk.top();
        stk.pop();
        if(cur->right!=NULL) goLeft(cur->right);
        if (!cur->left && !cur->right) return cur->val;
        return next();
    }
    bool hasNext()
    {
        return !stk.empty();
    }
    void goLeft(TreeNode* root)
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        LeafIterator leafy1(root1), leafy2(root2);
        while(leafy1.hasNext() && leafy2.hasNext())
        {
            int a = leafy1.next(), b = leafy2.next();
            // cout<<a<<','<<b<<endl;
            if(a!=b) return false;
        }
        bool a = !leafy1.hasNext() || leafy1.next()==-1;
        bool b = !leafy2.hasNext() || leafy2.next()==-1;
        return (a&b);
    }
};
 {% endhighlight %}