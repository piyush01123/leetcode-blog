class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(n):
            for j in range(i+1,n):
                S = set()
                for k in range(j+1,n):
                    if nums[k] in S:
                        quad = [nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]]
                        quad.sort()
                        if quad not in res:
                            res.append(quad)
                    S.add(target-nums[i]-nums[j]-nums[k])
        return res