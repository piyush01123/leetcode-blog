def mad(*args):
    sum = 0
    mod = 1000000007
    for val in args:
        sum += val
        sum %= mod
    return sum

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a,e,i,o,u, mod = 1,1,1,1,1, 10000007
        for _ in range(1,n):
            a, e, i, o, u = e, mad(a,i), mad(a,e,o,u), mad(i,u), a
        return mad(a,e,i,o,u)