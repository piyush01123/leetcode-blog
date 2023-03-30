class Solution:
    def existSum(self, nums,t,n):
        dp = [False]*(t+1)
        dp[0] = True
        for n in nums:
            for i in range(t,0,-1):
                if i>=n:
                    dp[i] = dp[i] or dp[i-n]
        return dp[t]
    def canPartition(self, nums: List[int]) -> bool:
        S = sum(nums)
        if S%2==1:
            return False
        t = S//2
        return self.existSum(nums,t,len(nums))