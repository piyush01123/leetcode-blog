# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # using extra space
        A = []
        while l1:
            A.append(l1.val)
            l1 = l1.next
        B = []
        while l2:
            B.append(l2.val)
            l2 = l2.next
        C=sorted(A+B)
        if not C:
            return None
        l3 = ListNode(C[0])
        curr = l3
        for c in C[1:]:
            curr.next = ListNode(c)
            curr = curr.next
        return l3
        #without using extra space