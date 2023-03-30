class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = s
        s = list(s); t = list(t); L = len(s)
        v = list('aeiouAEIOU')
        vpos=[]
        for i, alphabet in enumerate(s):
            if alphabet in v:
                vpos.append(i)
        # print(vpos)
        for i, pos in enumerate(vpos):
            t[pos] = s[vpos[-i-1]]
        return ''.join(t)
        