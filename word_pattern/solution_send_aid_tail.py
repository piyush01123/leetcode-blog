class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        if len(s.split())!=len(pattern): return False
        w2l, l2w = {},{}
        for word,letter in zip(s.split(), pattern):
            if word in w2l and w2l[word]!=letter:
                return False
            if letter in l2w and l2w[letter]!=word:
                return False
            w2l[word]=letter
            l2w[letter]=word
        return True

