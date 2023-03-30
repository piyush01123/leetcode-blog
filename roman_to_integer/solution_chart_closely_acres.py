class Solution:
    def romanToInt(self, s: str) -> int:
        values = {s: v for s,v in zip("IVXLCDM", [1,5,10,50,100,500,1000])}
        res = values[s[-1]]
        for i in range(len(s)-1):
            curr, next = values[s[i]], values[s[i+1]]
            res += curr if curr>=next else -curr
        return res