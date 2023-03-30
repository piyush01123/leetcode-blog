# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        A = []
        while head is not None:
            A.append(head.val)
            head = head.next
        B = [a for a in A if a<x]
        C = [a for a in A if a>= x]
        mylst = ListNode(None)
        curr = mylst
        for el in B+C:
            curr.next = ListNode(el)
            curr = curr.next
        return mylst.next
        