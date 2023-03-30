class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ctr, res = 1, 1
        for i in range(1,len(prices)):
            if prices[i]-prices[i-1]==-1:
                ctr += 1
            else:
                ctr = 1
            res += ctr
        return res