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

#define pi pair<int,int>
#define mp make_pair

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n=lists.size();
        if (n==0) return NULL;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (int i=0; i<n; i++)
        {
            auto list = lists[i];
            if (list==NULL) continue;
            pq.push(mp(list->val, i));
            lists[i] = list->next;
        }
        ListNode *res = new ListNode;
        ListNode *curr = res;
        while (pq.size()>0)
        {
            pi p = pq.top();
            pq.pop();
            int val=p.first, idx=p.second;
            curr->next = new ListNode(val);
            curr = curr->next;
            if (lists[idx] != NULL)
            {
                pq.push(mp(lists[idx]->val,idx));
                lists[idx] = lists[idx]->next;                
            }            
        }
        return res->next;
    }
};