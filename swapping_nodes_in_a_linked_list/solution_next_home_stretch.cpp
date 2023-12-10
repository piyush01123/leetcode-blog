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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *left, *right=NULL;
        for (ListNode *cur=head; cur; cur=cur->next)
        {
            if (right) right=right->next;
            if (k<0) continue;
            if (--k==0)
            {
                left = cur;
                right = head;
            }
        }
        swap(left->val, right->val);
        return head;
    }
};