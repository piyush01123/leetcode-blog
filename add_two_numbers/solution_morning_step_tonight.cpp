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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *res = new ListNode(-1), *cur=res;
        int s=0, c=0;
        while (l1 && l2)
        {
            s = c + l1->val + l2->val;
            c=s/10; s%=10;
            cur->next = new ListNode(s);
            cur = cur->next;
            l1 = l1->next; l2 = l2->next;
        }
        while (l1)
        {
            s = c + l1->val;
            c=s/10; s%=10;
            cur->next = new ListNode(s);
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2)
        {
            s = c + l2->val;
            c=s/10; s%=10;
            cur->next = new ListNode(s);
            cur = cur->next;
            l2 = l2->next;
        }
        if (c) cur->next = new ListNode(c);
        return res->next;
    }
};