class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = sorted(nums1+nums2)
        N = len(nums)
        if N%2 == 1:
            return nums[N//2]
        else:
            return (nums[N//2 - 1] + nums[N//2])/2
        
        