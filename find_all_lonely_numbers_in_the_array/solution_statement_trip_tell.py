class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        counter = collections.Counter(nums)
        res = []
        for item, freq in counter.items():
            if freq==1 and item-1 not in counter and item+1 not in counter:
                res.append(item)
        return res