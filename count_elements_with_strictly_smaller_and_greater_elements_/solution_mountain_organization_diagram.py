class Solution:
    def countElements(self, nums: List[int]) -> int:
        counter = collections.Counter(nums)
        return len([n for n in nums if min(counter)<n<max(counter)])