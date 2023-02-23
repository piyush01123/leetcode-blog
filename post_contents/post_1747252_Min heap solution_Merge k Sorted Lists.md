Algorithm:
- Create a min heap of the first item of each LL.
- While min heap is not empty pop the top of heap and check which LL it is coming from.
- Move ahead one step on that particular LL.
- When heap is empty stop.

C++ Version:
```
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
```
Python version:
```
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if lists is None or len(lists) == 0:
            return None
        lists = [lst for lst in lists if lst is not None]
        import heapq
        H = []
        for i, lst in enumerate(lists):
            heapq.heappush(H, (lst.val, i))
            lst = lst.next
        # print(H)
        mylst = ListNode(None)
        curr = mylst
        while len(H) > 0:
            # print("Heap", H)
            listval, listidx = heapq.heappop(H)
            # print(listval, listidx)
            curr.next = ListNode(listval)
            if lists[listidx].next is not None:
                lists[listidx] = lists[listidx].next
                heapq.heappush(H, (lists[listidx].val, listidx))
            curr = curr.next
        return mylst.next
```