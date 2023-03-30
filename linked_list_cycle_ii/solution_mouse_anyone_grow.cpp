/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *curr = head;
        unordered_set<ListNode *> S;
        while (curr)
        {
            if (S.find(curr)!=S.end()) return curr;
            S.insert(curr);
            curr = curr->next;
        }
        return NULL;        
    }
};