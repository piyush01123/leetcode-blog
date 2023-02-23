We can move all values one node to the left.
```
    void deleteNode(ListNode* node) 
    {
        ListNode *curr = node, *prev;
        while (curr->next)
        {
            curr->val = curr->next->val;
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
    }
```
This solution has O(N) TC and is accepted.

However we can do better! We can just update `node->val` and make `node->next` point to `node->next->next`. That should suffice.
```
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
```

This solution has O(1) TC and has good score.
We can make the code shorter! We can achieve the above with just one line:
```
    void deleteNode(ListNode* node) 
    {
        *node = *(node->next);
    }
```
This is also O(1), same as 2nd one. The one-liner thing is just a flex, you don"t need it in a real iterview. 2nd solution is best in my opinion.