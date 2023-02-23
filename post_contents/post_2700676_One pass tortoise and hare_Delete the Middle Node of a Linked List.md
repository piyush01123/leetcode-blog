```
ListNode* deleteMiddle(ListNode* head) 
{
    if (!head->next) return NULL;
    if (!head->next->next) return new ListNode(head->val);

    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *slow = *(slow->next);
    return head;
}
```