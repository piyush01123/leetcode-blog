class Solution:
    def countVowelPermutation(self, n: int) -> int:
        if n==1: return 5
        counter = [3,2,2,1,2]
        for i in range(n-2):
            a,e,i,o,u = counter
            counter = [e+i+u, a+i, e+o, i, i+o]
        return sum(counter)%(10**9+7)
        