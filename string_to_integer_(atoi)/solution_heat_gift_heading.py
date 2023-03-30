class Solution:
    def myAtoi(self, s: str) -> int:
        s, sign, i, curr, m, M = list(s.strip()), 1, 0, 0, -2**31, 2**31-1
        if len(s)==0: return 0
        if s[i]=='-': 
            sign = -1
        if s[i] in "+-":
            del s[i]
        if len(s)==0: return 0
        if not ord('0')<=ord(s[i])<=ord('9'):
            return 0
        while  i<len(s) and ord('0')<=ord(s[i])<=ord('9'):
            curr = 10*curr + ord(s[i])-ord('0')
            i += 1
        return min(M, max(m, sign*curr))