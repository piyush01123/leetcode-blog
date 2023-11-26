class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        for _ in range(n-1):
            nums = [(a+b)%10 for a,b in zip(nums[1:], nums[:-1])]
        return nums[0]
