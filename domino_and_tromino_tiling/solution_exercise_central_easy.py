class Solution:
    def numTilings(self, n: int) -> int:
        if n<3: return n
        a,b,c,mod = 1,1,2,int(1e9+7)
        for _ in range(n-2): a,b,c = b, c, (2*c%mod+a%mod)%mod
        return c