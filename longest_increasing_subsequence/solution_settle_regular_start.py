class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [None]*n
        for i in range(n):
            smaller_indices = [j for j in range(i) if nums[i]>nums[j]]
            if len(smaller_indices)==0:
                dp[i]=1
            else:
                dp[i] = max([dp[j] for j in smaller_indices])+1
        return max(dp)