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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        vector<int>A;
        while(head){A.push_back(head->val);head=head->next;}
        vector<int>res;
        int i=0;
        while(i<A.size())
        {
            if(i==0 || A[i]>A[i-1]) {res.push_back(A[i]); i++; continue;}
            res.pop_back();
            while(i<A.size() && A[i]==A[i-1]) i++;
        }
        ListNode *resLL = new ListNode();
        ListNode *cur = resLL;
        for(int r: res) {cur->next = new ListNode(r); cur=cur->next;}
        return resLL->next;
    }
};
/*
res=[]
int i=0;
while(i<|A|)
{
    res.push(A[i]);
    if (i>0 && A[i]==A[i-1])
    {
        res.pop();
        while(i<|A| && A[i]==A[i-1]) i++;
    }
    i++;
}
*/