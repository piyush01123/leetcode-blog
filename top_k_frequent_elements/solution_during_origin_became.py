class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        res = sorted(counter.keys(), key=lambda i: counter[i], reverse=True)
        return res[:k]