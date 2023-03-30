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
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode *curr = head;
        while(curr)
        {
            curr=curr->next;
            n++;
        }
        curr = head;
        int res = 0;
        n--;
        while(curr)
        {
            res = res + curr->val*(1<<n);
            curr=curr->next;
            n--;
        }
        return res;
    }
};