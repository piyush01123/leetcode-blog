class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n, minLeft, minRight = len(nums), 10**9+1, 10**9+1
        if n<3: return False
        largestSmaller, sortedRight = [0 for _ in range(n)],[]
        for i in range(n-1,-1,-1):
            minRight = min(minRight, nums[i])
            if nums[i]==minRight:
                sortedRight.insert(0, nums[i])
                largestSmaller[i] = nums[i]
            else:
                pos = bisect_left(sortedRight, nums[i])
                largestSmaller[i] = sortedRight[pos-1]
                sortedRight.insert(pos, nums[i])
        # print(largestSmaller, sortedRight)
        for i in range(n):
            minLeft = min(minLeft, nums[i])
            # print(i,minLeft,nums[i],largestSmaller[i])
            if minLeft<nums[i] and minLeft<largestSmaller[i] and nums[i]>largestSmaller[i]:
                return True
        return False
        