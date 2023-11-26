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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left=head, *right=head;
        for (int i=1; i<k; i++) left=left->next;
        ListNode *cur=left;
        int n = k;
        while (cur){cur=cur->next; n++;}
        n--;
        for(int i=0; i<n-k; i++) right=right->next;
        swap(left->val, right->val);
        return head;
    }
};