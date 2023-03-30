---
layout: mypost
title: "Binary Search Tree Iterator - Two solutions: Easy and Medium"
tags: ["Stack", "Tree", "Design", "Binary Search Tree", "Binary Tree", "Iterator", "C++", "Medium"]
---
# Problem Statement:
<p>Implement the <code>BSTIterator</code> class that represents an iterator over the <strong><a href="https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)" target="_blank">in-order traversal</a></strong> of a binary search tree (BST):</p>

<ul>
	<li><code>BSTIterator(TreeNode root)</code> Initializes an object of the <code>BSTIterator</code> class. The <code>root</code> of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.</li>
	<li><code>boolean hasNext()</code> Returns <code>true</code> if there exists a number in the traversal to the right of the pointer, otherwise returns <code>false</code>.</li>
	<li><code>int next()</code> Moves the pointer to the right, then returns the number at the pointer.</li>
</ul>

<p>Notice that by initializing the pointer to a non-existent smallest number, the first call to <code>next()</code> will return the smallest element in the BST.</p>

<p>You may assume that <code>next()</code> calls will always be valid. That is, there will be at least a next number in the in-order traversal when <code>next()</code> is called.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png" style="width: 189px; height: 178px;" />
<pre>
<strong>Input</strong>
[&quot;BSTIterator&quot;, &quot;next&quot;, &quot;next&quot;, &quot;hasNext&quot;, &quot;next&quot;, &quot;hasNext&quot;, &quot;next&quot;, &quot;hasNext&quot;, &quot;next&quot;, &quot;hasNext&quot;]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
<strong>Output</strong>
[null, 3, 7, true, 9, true, 15, true, 20, false]

<strong>Explanation</strong>
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>hasNext</code>, and <code>next</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>Could you implement <code>next()</code> and <code>hasNext()</code> to run in average <code>O(1)</code> time and use&nbsp;<code>O(h)</code> memory, where <code>h</code> is the height of the tree?</li>
</ul>

# Solution:
# Easy Solution
Just traverse the array and store keys in an array. Then return answer from array.
 {% highlight cpp %} 
class BSTIterator {
public:
    vector<int>keys;
    int idx;
    void traverse(TreeNode *root, vector<int>&keys_v)
    {
        if (root==NULL) return;
        traverse(root->left, keys_v);
        keys_v.push_back(root->val);
        traverse(root->right, keys_v);
    }
    BSTIterator(TreeNode* root) {
        traverse(root, keys);
        idx=0;
    }
    
    int next() {
        return keys[idx++];
    }
    
    bool hasNext() {
        return idx < keys.size();
    }
};
 {% endhighlight %}
 {% highlight cpp %} 
TC: O(1)
SC: O(n)
 {% endhighlight %}
# Medium Solution
Use stack to go as left as possible accumulating the nodes. Then return from bottom left and move to right (Accumulate nodes from right node to left-wards).
 {% highlight cpp %} 
class BSTIterator {
public:
    stack<TreeNode *>nodes;
    void pushLeft(TreeNode *root)
    {
        while (root!=NULL)
        {
            nodes.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        if (nodes.size()>0)
        {
            TreeNode *leftBottom = nodes.top();
            nodes.pop();
            pushLeft(leftBottom->right);
            return leftBottom->val;
        }
        else return -1;
        
    }
    
    bool hasNext() {
        return nodes.size()>0;
    }
};

 {% endhighlight %}
 {% highlight cpp %} 
TC: \u03B8(1) 
SC: O(h)
 {% endhighlight %}