class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1: return s
        n = len(s)
        res = s[0:n:2*numRows-2]
        for i in range(1,numRows-1):
            a = s[i:n:2*numRows-2]
            b = s[2*numRows-2-i:n:2*numRows-2]
            c = ""
            for k in range(min(len(a),len(b))):
                c+=a[k]+b[k]
            x = min(len(a),len(b))
            for k in range(x,len(a)):
                c+=a[k]
            for k in range(x,len(b)):
                c+=b[k]
            res += c
        res += s[numRows-1:n:2*numRows-2]
        return res