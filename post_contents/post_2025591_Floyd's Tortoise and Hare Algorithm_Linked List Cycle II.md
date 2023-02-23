Consider a situation like this.
![](https://i.imgur.com/jGtHiGq.png)

Consider two pointers `tortoise` and `hare` which move at 1x and 2x respectively.
We know that `d(hare)=2d(tortoise)`. So, when they meet we have:
```
F+nC+a = 2(F+a)
```
LHS is for hare and RHS is for tortoise.
Then we make the tortoise start again from the beginning and hare from the meeting position itself but both at 1x. Then they meet exactly at the cycle start point because after F steps, tortoise is at `F` and hare is at `F+a+F`. But we know that `F+a=nC` from earlier equation. Hence hare is also at `F` and this node is the answer.

```
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
```

There is obviously also an easier O(N) space HashSet solution that gives you an AC but I think the Floyd"s algo solution is more useful in real life interview. For the sake of completion here is the HashSet solution:
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> S;
        while (head)
        {
            if (S.count(head)) return head;
            S.insert(head);
            head = head->next;
        }
        return NULL;        
    }
};
```

