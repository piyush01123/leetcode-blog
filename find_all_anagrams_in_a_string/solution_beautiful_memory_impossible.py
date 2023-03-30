class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        H_p = collections.Counter(p)
        H_s = collections.Counter(s[:len(p)])
        res = []
        if H_s==H_p:
            res.append(0)
        for i in range(1,len(s)-len(p)+1):
            ch1, ch2 = s[i-1], s[i+len(p)-1]
            H_s[ch1]-=1
            H_s[ch2]+=1
            if H_s==H_p:
                res.append(i)
        return res