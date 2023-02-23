Easy method is to use hashset and traverse. If you find an element already present in hashset, return it. 
```
ListNode *detectCycle(ListNode *head) {
	ListNode *curr = head;
	unordered_set<ListNode *> S;
	while (curr)
	{
		if (S.find(curr)!=S.end()) return curr;
		S.insert(curr);
		curr = curr->next;
	}
	return NULL;        
}
```
O(n) time and O(n) space complexity.

For O(1) space solution, we can use fast and slow pointers. If we encounter NULL ever, means there was no cycle. If cycle is present the two pointers will meet. Then we again traverse both slow and start nodes till they meet and then return it:
```
ListNode *detectCycle(ListNode *head) {
	if (!head || !head->next) return NULL;
	ListNode *start=head, *slow=head, *fast=head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)
		{
			while (start!=slow)
			{
				slow = slow->next;
				start = start->next;
			}
			return start;
		}
	}
	return NULL;
}
```