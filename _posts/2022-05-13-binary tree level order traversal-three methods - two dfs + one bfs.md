---
layout: mypost
title: "Binary Tree Level Order Traversal - Three methods - Two DFS + One BFS"
tags: ["Tree", "Breadth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, return <em>the level order traversal of its nodes&#39; values</em>. (i.e., from left to right, level by level).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[9,20],[15,7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

# Solution:
Method 1 is to get height of tree, then for each number less than tree height, traverse the tree and get all keys at that level using DFS.
 {% highlight cpp %} 
class Solution {
public:
    int height(TreeNode *root)
    {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void dfs(TreeNode *root, vector<int>&levelVals, int h)
    {
        if (!root || h<0) return;
        if (h==0) levelVals.push_back(root->val);
        dfs(root->left, levelVals, h-1);
        dfs(root->right, levelVals, h-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int H = height(root);
        vector<vector<int>> res;
        for (int h=0; h<H; h++)
        {
            vector<int> levelVals;
            dfs(root, levelVals, h);
            res.push_back(levelVals);
        }
        return res;
    }
};
 {% endhighlight %}
Method 2 is to do DFS without getting height. Use the logic that if while going down from top, we are at same level as the size of keys array we append a new array and store keys of lower level in new array. 
 {% highlight cpp %} 
class Solution {
public:
    void dfs(TreeNode *root, vector<vector<int>>&res, int level)
    {
        if (!root) return;
        if (res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        dfs(root->left, res, level+1);
        dfs(root->right, res, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        return res;
    }
};
 {% endhighlight %}

BFS Solution:
Here we will need a queue. The children of the level nodes are stored in queue. Then one by one we go over the queue.
 {% highlight cpp %} 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root) return {};
        vector<vector<int>>res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            vector<int> levelVals;
			// We cant go from 0 to Q.size() because Q.size() changes inside for loop
			// Hence we initialize i once using Q.size() and iterate in reverse.
            for (int i=Q.size()-1; i>=0; i--)
            {
                TreeNode *node = Q.front();
                Q.pop();
                levelVals.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
            res.push_back(levelVals);
        }
        return res;
    }
};
 {% endhighlight %}