class Solution:
    def countVowelPermutation(self, n: int) -> int:
        if n==1: return 5
        duets = [1,2,4,2,1]
        words = [[1,1,1,1,1],[3,2,2,1,2]]
        for i in range(2,n):
            a,e,i,o,u = words[i-1]
            word = [e+i+u, a+i, e+o, i, i+o]
            words.append(word)
            # print(words)
        return sum(words[-1])%(10**9+7)
        