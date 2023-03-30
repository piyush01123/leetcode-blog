class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        return max(list(range(len(nums))), key=lambda k: nums[k])