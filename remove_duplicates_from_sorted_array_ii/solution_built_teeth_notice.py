class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        H = collections.Counter(nums)
        for k,v in H.items():
            H[k] = min(v,2)
        K = sum(H.values())
        i = 0
        for k in sorted(list(H.keys())):
            v = H[k]
            nums[i:i+v] = [k]*v
            i+=v
        return K