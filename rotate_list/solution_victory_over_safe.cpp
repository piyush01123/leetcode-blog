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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (k==0 || !head) return head;
        int n=0;
        ListNode *cur = head, *last=NULL;
        while(cur){last=cur; cur=cur->next; n++;}
        k %= n;
        if (k==0) return head;
        cur = head;
        for(int i=0;i<n-k-1;i++) cur=cur->next;
        ListNode *res = cur->next;
        last->next = head;
        cur->next = NULL;
        return res;
    }
};