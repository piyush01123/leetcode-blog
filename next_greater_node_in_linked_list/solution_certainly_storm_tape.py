# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        arr = []
        while head is not None:
            arr.append(head.val)
            head = head.next
        n = len(arr)
        if arr[::-1] == sorted(arr):
            return [0]*n
        ans = [None for _ in range(n)]
        for i in range(n):
            found=False
            for j in range(i+1,n):
                if arr[j]>arr[i]:
                    found=True
                    break
            if found:
                for k in range(i,j):
                    ans[k] = arr[j]
                    i = j
            else:
                ans[i] = 0
        return ans