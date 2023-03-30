# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        A = set()
        while headA:
            A.add(headA)
            headA = headA.next
        while headB:
            # print(A)
            if headB in A:
                return headB
            A.add(headB)
            headB = headB.next
        
        