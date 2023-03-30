---
layout: mypost
title: "Merge k Sorted Lists - Min heap solution"
tags: ["Linked List", "Divide and Conquer", "Heap (Priority Queue)", "Merge Sort", "Python", "C", "Hard"]
---
# Problem Statement:
<p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>

<p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
merging them into one sorted list:
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> lists = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> lists = [[]]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= lists[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>The sum of <code>lists[i].length</code> will not exceed <code>10<sup>4</sup></code>.</li>
</ul>

# Solution:
Algorithm:
- Create a min heap of the first item of each LL.
- While min heap is not empty pop the top of heap and check which LL it is coming from.
- Move ahead one step on that particular LL.
- When heap is empty stop.

C++ Version:
 {% highlight python %} 
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

#define pi pair<int,int>
#define mp make_pair

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n=lists.size();
        if (n==0) return NULL;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (int i=0; i<n; i++)
        {
            auto list = lists[i];
            if (list==NULL) continue;
            pq.push(mp(list->val, i));
            lists[i] = list->next;
        }
        ListNode *res = new ListNode;
        ListNode *curr = res;
        while (pq.size()>0)
        {
            pi p = pq.top();
            pq.pop();
            int val=p.first, idx=p.second;
            curr->next = new ListNode(val);
            curr = curr->next;
            if (lists[idx] != NULL)
            {
                pq.push(mp(lists[idx]->val,idx));
                lists[idx] = lists[idx]->next;                
            }            
        }
        return res->next;
    }
};
 {% endhighlight %}
Python version:
 {% highlight python %} 
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if lists is None or len(lists) == 0:
            return None
        lists = [lst for lst in lists if lst is not None]
        import heapq
        H = []
        for i, lst in enumerate(lists):
            heapq.heappush(H, (lst.val, i))
            lst = lst.next
        # print(H)
        mylst = ListNode(None)
        curr = mylst
        while len(H) > 0:
            # print('Heap', H)
            listval, listidx = heapq.heappop(H)
            # print(listval, listidx)
            curr.next = ListNode(listval)
            if lists[listidx].next is not None:
                lists[listidx] = lists[listidx].next
                heapq.heappush(H, (lists[listidx].val, listidx))
            curr = curr.next
        return mylst.next
 {% endhighlight %}