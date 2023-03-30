# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: 'ListNode') -> 'ListNode':
        # Using Extra space
        A = []
        curr = head
        while curr is not None:
            A.append(curr.val)
            curr = curr.next
        curr = h2 = ListNode('*')
        for a in A[::-1]:
            curr.next = ListNode(x=a)
            curr = curr.next
        return h2.next