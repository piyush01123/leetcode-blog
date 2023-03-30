class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        counter = collections.Counter(nums)
        return [n for n in nums if counter[n]==1 and counter[n-1]==counter[n+1]==0]