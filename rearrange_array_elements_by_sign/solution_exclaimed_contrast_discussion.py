class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos, neg = [n for n in nums if n>0], [n for n in nums if n<0]
        res = []
        for a,b in zip(pos,neg):
            res.append(a)
            res.append(b)
        return res