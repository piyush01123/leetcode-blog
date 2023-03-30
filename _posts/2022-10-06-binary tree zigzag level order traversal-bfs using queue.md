---
layout: mypost
title: "Binary Tree Zigzag Level Order Traversal - BFS using Queue"
tags: ["Tree", "Breadth-First Search", "Binary Tree", "C++", "Queue", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, return <em>the zigzag level order traversal of its nodes&#39; values</em>. (i.e., from left to right, then right to left for the next level and alternate between).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[20,9],[15,7]]
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
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

# Solution:
This is a standard BFS problem. BFS traversal always will use a queue and the way it works is you add all the adjoining nodes of current node to queue. Then for these newly added nodes traverse and add their children to the queue but remember to not traverse these children ie mark till where we had added the adjoining and traverse only till there. 

 {% highlight cpp %} 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if  (!root) return {};
        queue<TreeNode *> Q;
        Q.push(root);
        int level = 1;
        vector<vector<int>> res;
        while(!Q.empty())
        {
            vector<int> levelVals;
            for (int i=Q.size()-1; i>=0; --i)
            {
                TreeNode *node = Q.front();
                levelVals.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                Q.pop();
            }
            if (level%2 == 0)
                reverse(levelVals.begin(), levelVals.end());
            res.push_back(levelVals);
            level ++;
        }
        return res;
    }
};
 {% endhighlight %}

> Then for these newly added nodes traverse and add their children to the queue but remember to not traverse these children ie mark till where we had added the adjoining and traverse only till there.

For this reason in the inner for loop,
 {% highlight cpp %} 
            for (int i=Q.size()-1; i>=0; --i)
 {% endhighlight %}
works but the following wont work. Although the difference is very subtle.
 {% highlight cpp %} 
            for (int i=0; i<Q.size(); ++i)
 {% endhighlight %}
This is because `Q.size()` is going to change inside for loop so it can be used as initializer but not for termination criterion.