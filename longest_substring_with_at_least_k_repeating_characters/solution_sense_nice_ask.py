class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if k>len(s): return 0
        lfc = min(set(s), key=s.count) # least frequent character
        if s.count(lfc) >= k: return len(s)
        return max(self.longestSubstring(substr, k) for substr in s.split(lfc))