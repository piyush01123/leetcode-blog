class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        if part not in s:
            return s
        index = s.index(part)
        p = len(part)
        return self.removeOccurrences(s[:index]+s[index+p:], part)