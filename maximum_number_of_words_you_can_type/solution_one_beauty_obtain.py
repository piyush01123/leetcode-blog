class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        return len([w for w in text.split() if not set(w).intersection(brokenLetters)])