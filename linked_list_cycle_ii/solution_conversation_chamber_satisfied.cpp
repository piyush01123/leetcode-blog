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
    ListNode *detectCycle(ListNode *head) 
    {
        if (!head) return head;
        ListNode *hare = head, *tortoise = head;
        while (hare->next && hare->next->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if (hare==tortoise)
            {
                hare = head;
                while(hare!=tortoise)
                {
                    hare = hare->next;
                    tortoise = tortoise->next;
                }
                return hare;
            }
        }
        return NULL;
    }
};