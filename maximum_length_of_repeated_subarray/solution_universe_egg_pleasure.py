class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        A, B = nums1, nums2
        memo = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]
        for i in range(len(A)):
            for j in range(len(B)):
                if A[i]==B[j]:
                    memo[i][j] = memo[i-1][j-1]+1
        return max(max(row) for row in memo)
