class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        F0 = sum([i*n for i,n in enumerate(nums)])
        S = sum(nums)
        F = F0
        N = len(nums)
        curr_max = F
        for k in range(1,N):
            F = F+S-len(nums)*nums[-k]
            if F>curr_max:
                curr_max = F
        return curr_max
