class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        target = 0
        n = len(nums)
        nums.sort()
        for i in range(n-2):
            lo,hi = i+1,n-1
            while lo<hi:
                if nums[i]+nums[lo]+nums[hi]==target:
                    triplet = sorted([nums[i],nums[lo],nums[hi]])
                    if triplet not in res:
                        res.append(triplet)
                    lo+=1
                    hi-=1
                elif nums[i]+nums[lo]+nums[hi]<target:
                    lo+=1
                else:
                    hi-=1
        return res
