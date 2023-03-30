class Solution:
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        while i<=len(nums)-3:
            if nums[i] != nums[i+1]:
                return nums[i]
            i+=2
        return nums[-1]
            
        