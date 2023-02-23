```
ListNode* swapPairs(ListNode* head) 
{
	if (head==NULL || head->next==NULL) return head;
	ListNode *res = new ListNode(head->next->val);
	res->next = new ListNode(head->val);
	res->next->next = swapPairs(head->next->next);
	return res;
}
```