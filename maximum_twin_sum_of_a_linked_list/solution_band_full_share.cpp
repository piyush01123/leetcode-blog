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
    int pairSum(ListNode* head) {
        vector<int> A;
        while (head)
        {
            A.push_back(head->val);
            head = head->next;
        }
        int n=A.size()/2, maxVal=-1;
        for (int i=0; i<n; i++) maxVal= max(A[i]+A[2*n-i-1], maxVal);
        return maxVal;
    }
};