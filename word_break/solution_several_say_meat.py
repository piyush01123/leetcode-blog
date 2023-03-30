class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        L = len(s)
        ok = [True]
        for i in range(1, L+1):
            ok.append(any(ok[j] and s[j:i] in wordDict for j in range(i)))
        # print(ok)
        return ok[-1]

        