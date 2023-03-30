class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.upper()
        s = ''.join(S.split('-'))
        if len(s)==0:
            return ""
        elif len(s)<=K:
            return s
        r = len(s)%K
        s1 = s[:r] 
        s2 = s[r:]
        l = [s2[i:i+K] for i in range(0, len(s2), K)]
        if len(s1)==0:
            s1 = l.pop(0)
        return s1 + '-' + '-'.join(l)
        
        
        