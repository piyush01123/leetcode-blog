class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        H = Counter(nums)
        return max(H, key=lambda k: H[k])