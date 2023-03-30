---
layout: mypost
title: "Linked List Cycle II - An easy and a difficult solution"
tags: ["Hash Table", "Linked List", "Two Pointers", "Medium"]
---
# Problem Statement:
<p>Given the <code>head</code> of a linked list, return <em>the node where the cycle begins. If there is no cycle, return </em><code>null</code>.</p>

<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the <code>next</code> pointer. Internally, <code>pos</code> is used to denote the index of the node that tail&#39;s <code>next</code> pointer is connected to (<strong>0-indexed</strong>). It is <code>-1</code> if there is no cycle. <strong>Note that</strong> <code>pos</code> <strong>is not passed as a parameter</strong>.</p>

<p><strong>Do not modify</strong> the linked list.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="height: 145px; width: 450px;" />
<pre>
<strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> tail connects to node index 1
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the second node.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 105px; width: 201px;" />
<pre>
<strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> tail connects to node index 0
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the first node.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 65px; width: 65px;" />
<pre>
<strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> no cycle
<strong>Explanation:</strong> There is no cycle in the linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> is <code>-1</code> or a <strong>valid index</strong> in the linked-list.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve it using <code>O(1)</code> (i.e. constant) memory?</p>

# Solution:
Easy method is to use hashset and traverse. If you find an element already present in hashset, return it. 
```
ListNode *detectCycle(ListNode *head) {
	ListNode *curr = head;
	unordered_set<ListNode *> S;
	while (curr)
	{
		if (S.find(curr)!=S.end()) return curr;
		S.insert(curr);
		curr = curr->next;
	}
	return NULL;        
}
```
O(n) time and O(n) space complexity.

For O(1) space solution, we can use fast and slow pointers. If we encounter NULL ever, means there was no cycle. If cycle is present the two pointers will meet. Then we again traverse both slow and start nodes till they meet and then return it:
```
ListNode *detectCycle(ListNode *head) {
	if (!head || !head->next) return NULL;
	ListNode *start=head, *slow=head, *fast=head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)
		{
			while (start!=slow)
			{
				slow = slow->next;
				start = start->next;
			}
			return start;
		}
	}
	return NULL;
}
```