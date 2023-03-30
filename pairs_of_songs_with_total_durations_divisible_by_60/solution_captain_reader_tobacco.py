class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        res = 0
        comps = [0]*60
        for t in time:
            res += comps[t%60]
            comps[(60-t%60)%60] += 1
        return res