---
layout: mypost
title: "Linked List Cycle II - Floyd's Tortoise and Hare Algorithm"
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
Consider a situation like this.
![](https://i.imgur.com/jGtHiGq.png)

Consider two pointers `tortoise` and `hare` which move at 1x and 2x respectively.
We know that `d(hare)=2d(tortoise)`. So, when they meet we have:
```
F+nC+a = 2(F+a)
```
LHS is for hare and RHS is for tortoise.
Then we make the tortoise start again from the beginning and hare from the meeting position itself but both at 1x. Then they meet exactly at the cycle start point because after F steps, tortoise is at `F` and hare is at `F+a+F`. But we know that `F+a=nC` from earlier equation. Hence hare is also at `F` and this node is the answer.

```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *tortoise=head, *hare=head;
        while(1)
        {
            if (!hare||!hare->next) return NULL;
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise==hare) break;
        }
        tortoise = head;
        while (tortoise!=hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return hare;
    }
};
```

There is obviously also an easier O(N) space HashSet solution that gives you an AC but I think the Floyd's algo solution is more useful in real life interview. For the sake of completion here is the HashSet solution:
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> S;
        while (head)
        {
            if (S.count(head)) return head;
            S.insert(head);
            head = head->next;
        }
        return NULL;        
    }
};
```

