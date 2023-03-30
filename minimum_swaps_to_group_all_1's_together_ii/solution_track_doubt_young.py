class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ones, n = sum(nums), len(nums)
        curr = sum(nums[:ones])
        res = curr
        numsTwice = nums+nums
        for i in range(ones,2*n):
            curr += numsTwice[i]-numsTwice[i-ones]
            res = max(res, curr)
        return ones-res