class Solution:
    def customSortString(self, order: str, str: str) -> str:
        freq = [0 for _ in range(26)]
        for c in str:
            freq[ord(c)-ord('a')]+=1
        res = ""
        for c in order:
            res = res+c*freq[ord(c)-ord('a')]
        for c in set(list(str))-set(list(order)):
            res = res+c*freq[ord(c)-ord('a')]            
        return res