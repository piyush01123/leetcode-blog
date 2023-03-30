# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode()
        ans = l3
        carry = 0
        while (l1!=None and l2!=None):
            s = l1.val+l2.val+carry
            d, c = s%10, s//10
            l3.next = ListNode(d)
            carry = c
            l1 = l1.next
            l2 = l2.next
            l3 = l3.next
        while (l1!=None):
            s = l1.val+carry
            d, c = s%10, s//10
            l3.next = ListNode(d)
            carry = c
            l1 = l1.next
            l3 = l3.next
        while (l2!=None):
            s = l2.val+carry
            d, c = s%10, s//10
            l3.next = ListNode(d)
            carry = c
            l2 = l2.next
            l3 = l3.next
        if carry!=0:
            l3.next = ListNode(carry)
            l3 = l3.next
        return ans.next


