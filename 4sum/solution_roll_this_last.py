class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(n):
            for j in range(i):
                two_sum_target = target-nums[i]-nums[j]
                s = set()
                for k in range(j):
                    if nums[k] in s:
                        quadruplet = sorted([two_sum_target-nums[k],nums[i],nums[j],nums[k]])
                        if quadruplet not in res:
                            res.append(quadruplet)
                    s.add(two_sum_target-nums[k])
        return res