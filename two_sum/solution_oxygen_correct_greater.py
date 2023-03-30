
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        comps = {}
        for i, num in enumerate(nums):
            if num in comps:
                return [comps[num], i]
            comps[target-num] = i
        
