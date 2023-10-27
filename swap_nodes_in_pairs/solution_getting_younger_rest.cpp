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
    ListNode* swapPairs(ListNode* head) 
    {
        if (head==NULL || head->next==NULL) return head;
        ListNode *res = new ListNode(head->next->val);
        res->next = new ListNode(head->val);
        res->next->next = swapPairs(head->next->next);
        return res;
    }
};