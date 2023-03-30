class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = [l for l in s if l in "abcdefghijklmnopqrstuvwxyz0123456789"]
        return s==s[::-1]