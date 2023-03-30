class Solution:
            
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums)==0:
            return [-1, -1]
        if len(nums)==1:
            if nums[0]==target:
                return [0, 0]
            else:
                return [-1, -1]

        #finding left index
        low = 0
        high = len(nums) - 1
        while high>=low:
            mid = (low+high)//2
            print(mid)
            if target <= nums[mid]:
                high = mid-1
            else:
                low = mid+1
        if low>=len(nums):
            low=len(nums)-1
        print('low', low)
        left = low if nums[low]==target else -1
        print('part2')

        low = 0
        high = len(nums) - 1
        while high>=low:
            mid = (low+high)//2
            print(mid)
            if target >= nums[mid]:
                low = mid+1
            else:
                high = mid-1
        right = high if nums[high]==target else -1
        return [left, right]
                
                
        