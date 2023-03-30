# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        result = ListNode('Dummy Node')
        curr = result
        while l1 or l2:
            if not l1:
                sum = l2.val + carry
            elif not l2:
                sum = l1.val + carry
            else:
                sum = l1.val+l2.val+carry
            digit = sum%10
            carry = sum//10
            curr.next = ListNode(digit)
            curr = curr.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry>0:
            curr.next = ListNode(carry)
        return result.next
        