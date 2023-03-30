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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *curr = head;
        int n = 0;
        while(curr!=NULL)
        {
            curr = curr->next;
            n++;
        }
        if(n==1) return NULL;
        int i = 1;
        ListNode *res = head;
        curr = res;
        while(i<(int)n/2)
        {
            curr = curr->next;
            i++;
        }
        curr->next = curr->next->next;
        return res;
    }
};