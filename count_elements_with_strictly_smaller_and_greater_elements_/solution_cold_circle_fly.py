class Solution:
    def countElements(self, nums: List[int]) -> int:
        counter = collections.Counter(nums)
        if len(counter)<3: return 0
        m, M = min(counter), max(counter)
        print(counter, m, M)
        return len(nums)-counter[m]-counter[M]