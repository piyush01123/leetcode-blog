---
layout: mypost
title: "Find Mode in Binary Search Tree - Two solutions: O(h) space and O(1) space"
tags: ["Tree", "Depth-First Search", "Binary Search Tree", "Binary Tree", "C++", "Iterator", "Easy"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary search tree (BST) with duplicates, return <em>all the <a href="https://en.wikipedia.org/wiki/Mode_(statistics)" target="_blank">mode(s)</a> (i.e., the most frequently occurred element) in it</em>.</p>

<p>If the tree has more than one mode, return them in <strong>any order</strong>.</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than or equal to</strong> the node&#39;s key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than or equal to</strong> the node&#39;s key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg" style="width: 142px; height: 222px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
# Solution:
I will present two solutions. First one is based on [Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) which is `O(h)` in space where `h` is the height of tree and second is `O(1)` in space based on inorder traversal.

In both the solutions, we need the following idea:

**Consider this problem:**
Given a stream of integers in sorted order, find the mode(s) at any point.
How do you do this without mantaining a frequency map?

Following is a code snippet that gives this idea:
 {% highlight cpp %} 
int cur_elem = arr[0], cur_count = 1;
int max_elem = arr[0], max_count = 1;
vector<int> modes; modes.push_back(arr[0]);

for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == cur_elem) cur_count++;
    else {cur_elem = arr[i]; cur_count = 1;}

    if (cur_count > max_count) {
        max_elem = cur_elem; max_count = cur_count;
        modes.clear(); modes.push_back(max_elem);
    }
    if (cur_count == max_count && cur_elem != max_elem)
        modes.push_back(cur_elem);
}
 {% endhighlight %}

Now that we know how to do this for a sorted array, we can do this exact same thing for a BST using an iterator which gives us this solution.

 {% highlight cpp %} 
class TreeIterator
{
public:
    stack<TreeNode*> nodes;
    TreeIterator(TreeNode *root){goLeft(root);}
    bool hasNext(){return !nodes.empty();}
    TreeNode *getNext()
    {
        TreeNode *cur = nodes.top();
        nodes.pop();
        if (cur->right) goLeft(cur->right);
        return cur;
    }
    void goLeft(TreeNode *root)
    {
        while(root){nodes.push(root); root=root->left;}
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) 
    {
        TreeIterator itr = TreeIterator(root);
        vector<int> res;
        int cur_elem=itr.getNext()->val, cur_count=1;
        int max_elem=cur_elem, max_count=1;
        res.push_back(cur_elem);
        while (itr.hasNext())
        {
            int elem = itr.getNext()->val;
            if (elem==cur_elem) cur_count ++;
            else
            {
                cur_elem = elem;
                cur_count = 1;
            }
            if (cur_count>max_count)
            {
                max_elem = cur_elem;
                max_count = cur_count;
                res.clear();
                res.push_back(max_elem);
            }
            if (cur_count==max_count && cur_elem!=max_elem) res.push_back(cur_elem);
        }
        return res;
    }
};
 {% endhighlight %}

A tree iterator requires `O(h)` space for the stack. We can do away with that using an inorder traversal.
 {% highlight cpp %} 
class Solution {
    vector<int> res;
    int cur_elem, cur_count, max_elem, max_count;
    bool first_element;

    void inorder(TreeNode *root)
    {
        if(!root) return;
        inorder(root->left);
        int elem = root->val;
        if (first_element)
        {
            first_element = false;
            cur_elem = elem;
            max_elem = elem;
            cur_count = 1;
            max_count = 1;
            res.push_back(elem);
            inorder(root->right);
            return;
        }
        if (elem==cur_elem) cur_count ++;
        else
        {
            cur_elem = elem;
            cur_count = 1;
        }
        if (cur_count>max_count)
        {
            max_elem = cur_elem;
            max_count = cur_count;
            res.clear();
            res.push_back(max_elem);
        }
        if (cur_count==max_count && cur_elem!=max_elem) res.push_back(cur_elem);
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        first_element = true;
        inorder(root);
        return res;
    }
};
 {% endhighlight %}