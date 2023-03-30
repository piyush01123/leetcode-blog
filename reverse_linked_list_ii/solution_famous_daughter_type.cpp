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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> L;
        ListNode *curr = head;
        while(curr)
        {
            L.push_back(curr->val);
            curr = curr->next;
        }
        vector<int>L1 (L.begin(), L.begin()+left-1);
        vector<int>L2 (L.begin()+left-1, L.begin()+right);
        vector<int>L3 (L.begin()+right, L.end());
        reverse(L2.begin(), L2.end());
        L1.insert(L1.end(), L2.begin(),L2.end());
        L1.insert(L1.end(), L3.begin(),L3.end());
        ListNode *header = new ListNode(L1[0]);
        curr = header;
        for (int i=1; i<L1.size(); i++)
        {
            curr->next = new ListNode(L1[i]);
            curr = curr->next;
        }
        return header;
    }
};