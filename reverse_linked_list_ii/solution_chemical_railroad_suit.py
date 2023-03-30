# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        L, curr = [], head
        while curr is not None:
            L.append(curr.val)
            curr = curr.next
        L = L[:left-1] + L[left-1:right][::-1] + L[right:]
        head = ListNode(L[0])
        curr = head
        for n in L[1:]:
            curr.next = ListNode(n)
            curr = curr.next
        return head