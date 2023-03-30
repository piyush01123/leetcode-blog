# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        addrs = []
        while head:
            if id(head) in addrs:
                return True
            addrs.append(id(head))
            head=head.next
        return False
        