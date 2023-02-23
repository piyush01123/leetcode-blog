Basically create two linked lists: one with nodes less than x and another with nodes greater than or equal to x. After that put 2nd LL at the tail of 1st LL. 
```
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
```

```
TC: O(N)
SC: O(1)
```