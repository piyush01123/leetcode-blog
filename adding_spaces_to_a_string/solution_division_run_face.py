class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        words = [s[:spaces[0]]]
        for i in range(len(spaces)-1):
            word = s[spaces[i]:spaces[i+1]]
            words.append(word)
        words.append(s[spaces[-1]:])
        return " ".join(words)