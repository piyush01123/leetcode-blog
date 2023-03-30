class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if target not in words: return -1
        n = len(words)
        indices = [i for i in range(n) if words[i]==target]
        distances = [min(abs(i-startIndex),abs(i+n-startIndex),abs(startIndex+n-i)) for i in indices]
        return min(distances)