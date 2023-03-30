class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        if part not in s:
            return s
        index = s.index(part)
        p = len(part)
        t = s[:index]+s[index+p:]
        # print(index, p, s[:index], s[index:index+p], s[index+p:])
        return self.removeOccurrences(t, part)