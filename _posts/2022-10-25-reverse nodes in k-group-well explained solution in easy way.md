---
layout: mypost
title: "Reverse Nodes in k-Group - Well explained solution in easy way"
tags: ["Linked List", "Recursion", "C++", "Hard"]
---
# Problem Statement:
<p>Given the <code>head</code> of a linked list, reverse the nodes of the list <code>k</code> at a time, and return <em>the modified list</em>.</p>

<p><code>k</code> is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of <code>k</code> then left-out nodes, in the end, should remain as it is.</p>

<p>You may not alter the values in the list&#39;s nodes, only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [2,1,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 3
<strong>Output:</strong> [3,2,1,4,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Can you solve the problem in <code>O(1)</code> extra memory space?</p>

# Solution:
Here is the code to reverse linked list:
 {% highlight cpp %} 
ListNode* reverse(ListNode* head) 
{
	ListNode *curr=head, *prev=NULL, *upcoming;
	while (curr)
	{
		upcoming = curr->next;
		curr->next = prev;
		prev = curr;
		curr = upcoming;
	}
	return prev;
}
 {% endhighlight %}
Code is pretty much self-explanatory. Here is an example:
 {% highlight cpp %} 
head=1,2,3,NULL
 {% endhighlight %}
After 1st iteration:
 {% highlight cpp %} 
head=1,NULL
prev=1,NULL
curr=2,3,NULL
 {% endhighlight %}
After 2nd iteration:
 {% highlight cpp %} 
head=1,NULL
prev=2,1,NULL
curr=3,NULL
 {% endhighlight %}
After 3rd iteration
 {% highlight cpp %} 
head=1,NULL
prev=3,2,1,NULL
curr=NULL
 {% endhighlight %}
Now it stops.

Now to solve our question and inspired from above logic, we replace constraint in `while(curr)` so that it stops when we have done k iterations. For example

 {% highlight cpp %} 
head=1,2,3,4,5,NULL
k=2
 {% endhighlight %}
When while loop stops we will have
 {% highlight cpp %} 
head=1,NULL
prev=2,1,NULL
curr=3,4,5,NULL
 {% endhighlight %}

Now we need to check if the remaining part of LL `3,4,5,NULL` requires reversal or not.
If it does, then we add the reverse part of the remaining LL to `head` which is still at `1`. If not we add the remaining LL without reversal to `head`. Finally return `prev`.

C++ code:

 {% highlight cpp %} 
class Solution {
public:
    bool countK(ListNode *node, int k)
    {
        int i=0;
        while (node && i<k)
        {
            node = node->next;
            i++;
        }
        return (i==k);
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *curr=head, *prev=NULL, *upcoming;
        int i=0;
        while (i<k)
        {
            upcoming = curr->next;
            curr->next = prev;
            prev = curr;
            curr = upcoming;
            i++;
        }
        if (curr && countK(curr, k))
            head->next = reverseKGroup(curr, k);
        else
            head->next = curr;
        return prev;
    }
};
 {% endhighlight %}