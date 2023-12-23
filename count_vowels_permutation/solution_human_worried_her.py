class Solution:
    def countVowelPermutation(self, n: int) -> int:
        def mad(*args):
            sum, mod = 0, 1000000007
            for val in args: sum = (sum+val)%mod
            return sum
        a,e,i,o,u, mod = 1,1,1,1,1, 10000007
        for _ in range(1,n):
            a, e, i, o, u = e, mad(a,i), mad(a,e,o,u), mad(i,u), a
        return mad(a,e,i,o,u)