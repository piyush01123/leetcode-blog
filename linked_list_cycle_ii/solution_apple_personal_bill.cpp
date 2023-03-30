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
        ListNode *tortoise=head, *hare=head;
        while(1)
        {
            if (!hare||!hare->next) return NULL;
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise==hare) break;
        }
        tortoise = head;
        while (tortoise!=hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return hare;
    }
};