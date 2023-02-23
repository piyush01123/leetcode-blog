Python has stuff like `split`, `reversed` and `join` which lets us write a 1-liner.
```
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))
```