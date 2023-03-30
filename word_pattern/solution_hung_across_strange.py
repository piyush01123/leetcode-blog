class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        if len(s.split())!=len(pattern): return False
        H1, H2 = dict(), dict()
        for word, letter in zip(s.split(), pattern):
            print(H1,H2)
            if word in H1:
                if H1[word]!=letter:
                    return False
            if letter in H2:
                if H2[letter]!=word:
                    return False
            H1[word] = letter
            H2[letter] = word
        return True