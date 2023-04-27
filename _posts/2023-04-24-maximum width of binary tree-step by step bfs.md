---
layout: mypost
title: "Maximum Width of Binary Tree - Step by step BFS"
tags: ["Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, return <em>the <strong>maximum width</strong> of the given tree</em>.</p>

<p>The <strong>maximum width</strong> of a tree is the maximum <strong>width</strong> among all levels.</p>

<p>The <strong>width</strong> of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.</p>

<p>It is <strong>guaranteed</strong> that the answer will in the range of a <strong>32-bit</strong> signed integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg" style="width: 359px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum width exists in the third level with length 4 (5,3,null,9).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/14/maximum-width-of-binary-tree-v3.jpg" style="width: 442px; height: 422px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,null,null,9,6,null,7]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg" style="width: 289px; height: 299px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum width exists in the second level with length 2 (3,2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

# Solution:
Clearly this question pertains to BFS. Here is the skeleton of BFS in binary tree.
 {% highlight cpp %} 
void BFS(TreeNode* root)
{
    Q.push(root);
    while(!Q.empty())
    {
        for (int i=Q.size(); i>0; i--)
        {
            TreeNode* cur = Q.front();
            Q.pop();
            if(cur->left) Q.push(cur->left);
            if(cur->right) Q.push(cur->right);            
        }
    }
}

 {% endhighlight %}
To get width of tree, we can modify `node->val` of each node to be its serial number in a complete tree. Then for any level, the difference in the `val` attribute of left most and right most nodes is the width of that level. We can use this to find answer.
 {% highlight cpp %} 
int widthOfBinaryTree(TreeNode* root) 
{
    int res = 0;
    root->val = 0;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        res = max(res, 1+Q.back()->val-Q.front()->val);
        for (int i=Q.size(); i>0; i--)
        {
            TreeNode* cur = Q.front();
            Q.pop();
            if(cur->left) {cur->left->val = 2*cur->val+1; Q.push(cur->left);}
            if(cur->right) {cur->right->val = 2*cur->val+2; Q.push(cur->right);}
        }
    }
    return res;
}
 {% endhighlight %}
However, this fails for larger tree test cases because of overflow in `int`. So, we need to track this serial number of node in a separate variable. We can use `unsigned long long` dtype to track this serial number to avoid overflow issues.
 {% highlight cpp %} 
int widthOfBinaryTree(TreeNode* root) 
{
    unsigned long long res = 0;
    queue<pair<TreeNode*,unsigned long long>> Q;
    Q.push({root,0});
    while(!Q.empty())
    {
        res = max(res, 1+Q.back().second-Q.front().second);
        for (int i=Q.size(); i>0; i--)
        {
            TreeNode* cur = Q.front().first;
            auto curNum = Q.front().second;
            Q.pop();
            if(cur->left) Q.push({cur->left, 2*curNum+1});
            if(cur->right) Q.push({cur->right, 2*curNum+2});
        }
    }
    return (int)res;
}
 {% endhighlight %}
TC: $O(n)$, SC:$O(n)$