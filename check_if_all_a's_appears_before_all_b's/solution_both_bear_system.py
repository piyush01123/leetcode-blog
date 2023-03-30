class Solution:
    def checkString(self, s: str) -> bool:
        for index,char in enumerate(s):
            if char=='b':
                break
        return 'a' not in s[index+1:]
