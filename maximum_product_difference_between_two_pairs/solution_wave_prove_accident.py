class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        a_max, a_max2, a_min, a_min2 = -1e10,-1e10,1e10,1e10
        for num in nums:
            if num>a_max:
                a_max, a_max2 = num, a_max
            elif a_max>=num>a_max2:
                a_max2 = num
            else:
                pass
            if num<a_min:
                a_min, a_min2 = num, a_min
            elif a_min<=num<a_min2:
                a_min2 = num
            else:
                pass
        return a_max*a_max2 - a_min*a_min2
            