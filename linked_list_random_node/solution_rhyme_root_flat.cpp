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
    vector<int>vals;
    int n;
public:
    Solution(ListNode* head) {
        while(head!=NULL)
        {
            vals.push_back(head->val);
            head=head->next;
        }
        n = vals.size();
    }
    
    int getRandom() {
        int idx = rand()%n;
        return vals[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */