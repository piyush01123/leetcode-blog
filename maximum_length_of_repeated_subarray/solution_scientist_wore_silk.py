class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        A, B = nums1, nums2
        memo = [[0] * (len(B)) for _ in range(len(A))]
        for i in range(len(A)):
            for j in range(len(B)):
                if i==0 or j==0:
                    memo[i][j] = 1 if A[i]==B[j] else 0
                    continue
                if A[i]==B[j]:
                    memo[i][j] = memo[i-1][j-1]+1
        return max(max(row) for row in memo)
