# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        A = []
        while head is not None:
            A.append(head.val)
            head = head.next
        n, maxSum = len(A)//2, -1
        for i in range(n):
            if A[i]+A[-i-1]>maxSum:
                maxSum=A[i]+A[-i-1]
        return maxSum
        