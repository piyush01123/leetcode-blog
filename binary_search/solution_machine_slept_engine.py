class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums)==0:
            return -1
        if len(nums)==1:
            if nums[0]==target:
                return 0
            else:
                return -1
        
        first = 0
        last = len(nums) - 1
        
        while first<=last:
            mid = (first+last)//2
            if nums[mid] == target:
                return mid
            elif target<nums[mid]:
                last = mid - 1
            else:
                first = mid + 1            
        return -1
        