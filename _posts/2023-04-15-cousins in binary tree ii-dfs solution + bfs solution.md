---
layout: mypost
title: "Cousins in Binary Tree II - DFS solution + BFS solution"
tags: ["Hash Table", "Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, replace the value of each node in the tree with the <strong>sum of all its cousins&#39; values</strong>.</p>

<p>Two nodes of a binary tree are <strong>cousins</strong> if they have the same depth with different parents.</p>

<p>Return <em>the </em><code>root</code><em> of the modified tree</em>.</p>

<p><strong>Note</strong> that the depth of a node is the number of edges in the path from the root node to it.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/01/11/example11.png" style="width: 571px; height: 151px;" />
<pre>
<strong>Input:</strong> root = [5,4,9,1,10,null,7]
<strong>Output:</strong> [0,0,0,7,7,null,11]
<strong>Explanation:</strong> The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/01/11/diagram33.png" style="width: 481px; height: 91px;" />
<pre>
<strong>Input:</strong> root = [3,1,2]
<strong>Output:</strong> [0,0,0]
<strong>Explanation:</strong> The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
**DFS solution:** We use DFS twice. First time, to recursively compute level sums. During second time, for any `node` at level value `level` we modify values of level `level+1` as follows:
 {% highlight cpp %} 
int cousinSum = levels[level+1] - node->left - node->right;
node->left->val = node->right-val = cousinSum;
 {% endhighlight %}

Complete DFS solution:
 {% highlight cpp %} 
void dfsA(TreeNode *root, vector<int>&levels, int level)
{
    if (!root) return;
    if (levels.size()==level) levels.push_back(0);
    levels[level] += root->val;
    dfsA(root->left, levels, level+1);
    dfsA(root->right, levels, level+1);
}
void dfsB(TreeNode *root, vector<int> &levels, int level)
{
    if (!root) return;
    int cur = 0;
    if (root->left) cur += root->left->val;
    if (root->right) cur += root->right->val;
    if(root->left) root->left->val = levels[level+1]-cur;
    if (root->right) root->right->val = levels[level+1]-cur;
    dfsB(root->left, levels, level+1);
    dfsB(root->right, levels, level+1);
}
TreeNode* replaceValueInTree(TreeNode* root) 
{
    vector<int> levels;
    dfsA(root, levels, 0);
    dfsB(root, levels, 0);
    root->val = 0;
    return root;
}
 {% endhighlight %}
**BFS solution:** We can also modify BFS to do the same thing. During the traversal, instead of adding node values at current level, we add node values at next level. Then, we can use the equation described earlier to compute the same thing.

Complete BFS solution:
 {% highlight cpp %} 
TreeNode* replaceValueInTree(TreeNode* root) 
{
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        int curSum = 0;
        vector<TreeNode*> levelNodes;
        for (int i=Q.size(); i>0; i--)
        {
            TreeNode* cur = Q.front();
            Q.pop();
            levelNodes.push_back(cur);
            if (cur->left)
            {
                curSum += cur->left->val;
                Q.push(cur->left);
            }
            if (cur->right)
            {
                curSum += cur->right->val;
                Q.push(cur->right);
            }
        }
        for (TreeNode* node: levelNodes)
        {
            int cousinSum = curSum;
            if (node->left) cousinSum -= node->left->val;
            if (node->right) cousinSum -= node->right->val;
            if (node->left) node->left->val = cousinSum;
            if (node->right) node->right->val = cousinSum;
        }
    }
    root->val = 0;
    return root;
}
 {% endhighlight %}