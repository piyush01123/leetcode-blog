# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        curr = head
        i=0
        while i<n:
            curr=curr.next
            i+=1
        if curr is None:
            return head.next
        curr2 = answer = head
        while curr.next is not None:
            curr = curr.next
            curr2  = curr2.next
        curr2.next = curr2.next.next
        while curr2 is not None:
            curr2 = curr2.next
        return answer
