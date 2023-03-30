---
layout: mypost
title: "Convert Sorted List to Binary Search Tree - An elegant solution"
tags: ["Linked List", "Divide and Conquer", "Tree", "Binary Search Tree", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>head</code> of a singly linked list where elements are sorted in <strong>ascending order</strong>, convert <em>it to a </em><span data-keyword="height-balanced"><strong><em>height-balanced</em></strong></span> <em>binary search tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/linked.jpg" style="width: 500px; height: 388px;" />
<pre>
<strong>Input:</strong> head = [-10,-3,0,5,9]
<strong>Output:</strong> [0,-3,9,-10,null,5]
<strong>Explanation:</strong> One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in <code>head</code> is in the range <code>[0, 2 * 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
## Intuition
The underlying thought is actually pretty simple and common in linked list problems: a tortoise and a hare; 2 pointers that walk on linked lists at 1 node per step for tortoise and 2 nodes per step for hare. When the hare reaches the end, the tortoise has reached the mid of the linked list, which is to be the root of the BST. The left subtree is to the left of this node and the right subtree is to the right, hence we can use recursion to form both subtrees. The boundary line case is when there is no node to traverse, we return null pointer in this case.

## Code
 {% highlight cpp %} 
TreeNode* sortedListToBST(ListNode* head, ListNode *end=NULL) 
{
    if (head==end) return NULL;
    ListNode *fast = head, *slow = head;
    while (fast!=end && fast->next!=end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *cur = new TreeNode;
    cur->val = slow->val;
    cur->left = sortedListToBST(head, slow);
    cur->right = sortedListToBST(slow->next, end);
    return cur;
}
 {% endhighlight %}

TC: $O(n \log n)$
SC: $O(1)$