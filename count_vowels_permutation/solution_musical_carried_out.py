class Solution:
    def countVowelPermutation(self, n: int) -> int:
        if n==1: return 5
        a,e,i,o,u = 3,2,2,1,2
        for _ in range(n-2):
            a,e,i,o,u = e+i+u, a+i, e+o, i, i+o
        return (a+e+i+o+u)%(10**9+7)
                