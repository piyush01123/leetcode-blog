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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *curr1 = head, *curr2=head, *res;
        for (int i=0; i<n; i++) curr1 = curr1->next;
        if (!curr1) return head->next;
        res = curr2;
        while (curr1->next)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        curr2->next = curr2->next->next;
        return res;
    }
};