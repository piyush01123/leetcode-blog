# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        A = []
        while head is not None:
            A.append(head.val)
            head = head.next
        A.sort()
        mylist = ListNode(A[0])
        curr = mylist
        for a in A[1:]:
            curr.next = ListNode(a)
            curr = curr.next
        return mylist
        