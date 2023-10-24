---
layout: mypost
title: "Find Largest Value in Each Tree Row - BFS and DFS solutions"
tags: ["Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "C++", "Java", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, return <em>an array of the largest value in each row</em> of the tree <strong>(0-indexed)</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" style="width: 300px; height: 172px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> [1,3,9]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> [1,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

# Solution:
BFS in C++:
 {% highlight java %} 
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> res;
        while(!Q.empty())
        {
            int val = INT_MIN;
            for(int i=Q.size(); i>0; i--)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
                val = max(val, cur->val);
            }
            res.push_back(val);
        }
        return res;
    }
};
 {% endhighlight %}
BFS in Java:
 {% highlight java %} 
class Solution 
{
    public List<Integer> largestValues(TreeNode root) 
    {
        if (root==null) return new ArrayList();
        List<Integer> res = new ArrayList();
        Queue<TreeNode> Q = new LinkedList();
        Q.add(root);
        while(!Q.isEmpty())
        {
            int val = Integer.MIN_VALUE;
            for (int i=Q.size(); i>0;  i--)
            {
                TreeNode cur = Q.poll();
                if (cur.left!=null) Q.add(cur.left);
                if (cur.right!=null) Q.add(cur.right);
                val = Math.max(val, cur.val);
            }
            res.add(val);
        }
        return res;
    }
}
 {% endhighlight %}


DFS in C++:
 {% highlight java %} 
class Solution 
{
public:
    void dfs(TreeNode *root, vector<int>&res, int d)
    {
        if (!root) return;
        if (d==res.size()) res.push_back(root->val);
        res[d] = max(res[d], root->val);
        dfs(root->left, res, d+1);
        dfs(root->right, res, d+1);
    }
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};
 {% endhighlight %}

DFS in Java:
 {% highlight java %} 
class Solution 
{
    List<Integer> res;
    void dfs(TreeNode root, int d)
    {
        if (root==null) return;
        if (res.size()==d) res.add(root.val);
        res.set(d, Math.max(res.get(d), root.val));
        if (root.left!=null) dfs(root.left, d+1);
        if (root.right!=null) dfs(root.right, d+1);
    }
    public List<Integer> largestValues(TreeNode root) 
    {
        res = new ArrayList();
        dfs(root, 0);
        return res;
    }
}
 {% endhighlight %}