class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        target = 0
        n = len(nums)
        nums.sort()
        for i in range(n-2):
            two_sum_target = target-nums[i]
            s = set()
            for j in range(i+1,n):
                if nums[j] in s:
                    triplet = sorted([two_sum_target-nums[j],nums[j],nums[i]])
                    if triplet not in res:
                        res.append(triplet)
                s.add(two_sum_target-nums[j])
        return res
