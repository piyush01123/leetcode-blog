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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> S;
        while (head)
        {
            if (S.count(head)) return true;
            S.insert(head);
            head = head->next;
        }
        return false;
    }
};