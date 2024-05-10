---
layout: mypost
title: "Most Frequent Subtree Sum - Plain and simple DFS"
tags: ["Hash Table", "Tree", "Depth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, return the most frequent <strong>subtree sum</strong>. If there is a tie, return all the values with the highest frequency in any order.</p>

<p>The <strong>subtree sum</strong> of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/freq1-tree.jpg" style="width: 207px; height: 183px;" />
<pre>
<strong>Input:</strong> root = [5,2,-3]
<strong>Output:</strong> [2,-3,4]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/freq2-tree.jpg" style="width: 207px; height: 183px;" />
<pre>
<strong>Input:</strong> root = [5,2,-5]
<strong>Output:</strong> [2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
Basically there are two steps to this:
- Creating a frquency map of subtree sums
- Finding the key or keys with maximum value in a frequency map.

For first part, we can modify the basic DFS to maintain subtree sums and also increment a frequency map.

For the second part, we just iterate the frequency map to get the key or keys with maximum value.

 {% highlight cpp %} 
class Solution {
    unordered_map<int,int> H;
    int dfs(TreeNode *root)
    {
        if(!root) return 0;
        int cur = root->val + dfs(root->left) + dfs(root->right);
        H[cur]++;
        return cur;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        dfs(root);
        vector<int> res;
        int curMax = 0;
        for(auto &[k,v]: H)
        {
            if(v<curMax) continue;
            if(v==curMax){res.push_back(k); continue;}
            curMax = v;
            res.clear();
            res.push_back(k);
        }
        return res;
    }
};
 {% endhighlight %}