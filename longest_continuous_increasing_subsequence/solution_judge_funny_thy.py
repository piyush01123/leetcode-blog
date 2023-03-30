class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr, res, n = 1, 1, len(nums)
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                curr += 1
            else:
                if curr>res: 
                    res = curr
                curr = 1
        if curr>res:
            res = curr
        return res
                