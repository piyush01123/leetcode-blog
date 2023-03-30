---
layout: mypost
title: "Delete Node in a Linked List - 3 solutions"
tags: ["Linked List", "C++", "Medium"]
---
# Problem Statement:
<p>There is a singly-linked list <code>head</code> and we want to delete a node <code>node</code> in it.</p>

<p>You are given the node to be deleted <code>node</code>. You will <strong>not be given access</strong> to the first node of <code>head</code>.</p>

<p>All the values of the linked list are <strong>unique</strong>, and it is guaranteed that the given node <code>node</code> is not the last node in the linked list.</p>

<p>Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:</p>

<ul>
	<li>The value of the given node should not exist in the linked list.</li>
	<li>The number of nodes in the linked list should decrease by one.</li>
	<li>All the values before <code>node</code> should be in the same order.</li>
	<li>All the values after <code>node</code> should be in the same order.</li>
</ul>

<p><strong>Custom testing:</strong></p>

<ul>
	<li>For the input, you should provide the entire linked list <code>head</code> and the node to be given <code>node</code>. <code>node</code> should not be the last node of the list and should be an actual node in the list.</li>
	<li>We will build the linked list and pass the node to your function.</li>
	<li>The output will be the entire list after calling your function.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node1.jpg" style="width: 400px; height: 286px;" />
<pre>
<strong>Input:</strong> head = [4,5,1,9], node = 5
<strong>Output:</strong> [4,1,9]
<strong>Explanation: </strong>You are given the second node with value 5, the linked list should become 4 -&gt; 1 -&gt; 9 after calling your function.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node2.jpg" style="width: 400px; height: 315px;" />
<pre>
<strong>Input:</strong> head = [4,5,1,9], node = 1
<strong>Output:</strong> [4,5,9]
<strong>Explanation: </strong>You are given the third node with value 1, the linked list should become 4 -&gt; 5 -&gt; 9 after calling your function.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the given list is in the range <code>[2, 1000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>The value of each node in the list is <strong>unique</strong>.</li>
	<li>The <code>node</code> to be deleted is <strong>in the list</strong> and is <strong>not a tail</strong> node.</li>
</ul>

# Solution:
We can move all values one node to the left.
 {% highlight cpp %} 
    void deleteNode(ListNode* node) 
    {
        ListNode *curr = node, *prev;
        while (curr->next)
        {
            curr->val = curr->next->val;
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
    }
 {% endhighlight %}
This solution has O(N) TC and is accepted.

However we can do better! We can just update `node->val` and make `node->next` point to `node->next->next`. That should suffice.
 {% highlight cpp %} 
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
 {% endhighlight %}

This solution has O(1) TC and has good score.
We can make the code shorter! We can achieve the above with just one line:
 {% highlight cpp %} 
    void deleteNode(ListNode* node) 
    {
        *node = *(node->next);
    }
 {% endhighlight %}
This is also O(1), same as 2nd one. The one-liner thing is just a flex, you don't need it in a real iterview. 2nd solution is best in my opinion.