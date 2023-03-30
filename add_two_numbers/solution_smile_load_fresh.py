# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        a1,a2 = [],[]
        while l1!=None:
            a1.append(str(l1.val))
            l1 = l1.next
        while l2!=None:
            a2.append(str(l2.val))
            l2 = l2.next            
        n1,n2 = int(''.join(a1[::-1])), int(''.join(a2[::-1]))
        n3 = n1+n2
        a3 = (str(n3))[::-1]
        l3 = ListNode()
        ans = l3
        for digit in a3:
            l3.next = ListNode(int(digit))
            l3 = l3.next
        return ans.next
        