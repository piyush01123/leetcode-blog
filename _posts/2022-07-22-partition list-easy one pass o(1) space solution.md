---
layout: mypost
title: "Partition List - Easy One pass O(1) space solution"
tags: ["Linked List", "Two Pointers", "C++", "Medium"]
---
# Problem Statement:
<p>Given the <code>head</code> of a linked list and a value <code>x</code>, partition it such that all nodes <strong>less than</strong> <code>x</code> come before nodes <strong>greater than or equal</strong> to <code>x</code>.</p>

<p>You should <strong>preserve</strong> the original relative order of the nodes in each of the two partitions.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,4,3,2,5,2], x = 3
<strong>Output:</strong> [1,2,2,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [2,1], x = 2
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 200]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>-200 &lt;= x &lt;= 200</code></li>
</ul>

# Solution:
Basically create two linked lists: one with nodes less than x and another with nodes greater than or equal to x. After that put 2nd LL at the tail of 1st LL. 
 {% highlight cpp %} 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr=head, *head1=new ListNode, *head2=new ListNode;
        ListNode *curr1 = head1, *curr2=head2;
        while (curr)
        {
            if (curr->val<x)
            {
                curr1->next = new ListNode(curr->val);
                curr1 = curr1->next;
            }
            else
            {
                curr2->next = new ListNode(curr->val);
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        curr1->next = head2->next;
        return head1->next;
    }
};
 {% endhighlight %}

 {% highlight cpp %} 
TC: O(N)
SC: O(1)
 {% endhighlight %}