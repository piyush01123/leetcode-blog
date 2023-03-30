class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        counter = [1]+[0 for _ in range(1023)]
        curr = 0
        res = 0
        for ch in word:
            curr ^=  (1<<(ord(ch)-ord('a')))
            res += counter[curr]
            for i in range(10):
                res += counter[curr^(1<<i)]
            counter[curr]+=1
        return res
            
