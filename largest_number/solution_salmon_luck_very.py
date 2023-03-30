class Number:
    def __init__(self, x):
        self.x=x
    def __lt__(self, other):
        return self.x+other.x<other.x+self.x
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums_str = [Number(str(num)) for num in nums]
        order = sorted(range(len(nums)), key=lambda i: nums_str[i], reverse=True)
        return str(int(''.join(str(nums[i]) for i in order)))