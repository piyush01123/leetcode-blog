class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_ending_here = max_so_far = nums[0]
        for num in nums[1:]:
            max_ending_here = max(max_ending_here + num, num)
            max_so_far = max(max_so_far, max_ending_here)
            print(max_ending_here, max_so_far)
        return max_so_far
