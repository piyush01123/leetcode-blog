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
        while (curr && i<k)
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