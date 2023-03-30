class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        s += s
        s1, s2 = '01' * (n+1), '10' * (n+1)
        s1, s2 = s1[:2*n], s2[:2*n]
        assert len(s1)==len(s2)==2*n
        a, a1, a2 = 1e10, 0, 0
        for i in range(2*n):
            if s[i] != s1[i]:
                a1 += 1
            if s[i] != s2[i]:
                a2 += 1
            if i >= n:
                if s[i-n] != s1[i-n]:
                    a1 -= 1
                if s[i-n] != s2[i-n]:
                    a2 -= 1
            if i>=n-1:
                a = min(a1,a2,a)
        return a
            
