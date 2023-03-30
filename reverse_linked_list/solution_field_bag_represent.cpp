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
    ListNode* reverseList(ListNode* head) {
        vector<int>vals;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        ListNode *reverse = new ListNode;
        curr = reverse;
        for(int i=vals.size()-1; i>=0; i--)
        {
            curr->next = new ListNode;
            curr->next->val = vals[i];
            curr = curr->next;
        }
        return reverse->next;
    }
};