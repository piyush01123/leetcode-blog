class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if len(s)==0 or s[0] not in "-+0123456789": return 0
        sign = '+'
        if s[0] in "-+":
            sign = s[0]
            s = s[1:]
        if len(s)==0 or s[0] not in "0123456789": return 0
        fin = ""
        for c in s:
            if c not in "0123456789":
                break
            fin+=c
        if sign=='-':
            n = -int(fin)
        else:
            n = int(fin)
        if n<-2**31: return -2**31
        if n>=2**31: return 2**31-1
        return n