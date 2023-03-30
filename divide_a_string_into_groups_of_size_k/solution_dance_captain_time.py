class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        L = [s[k*i:k*(i+1)] for i in range(len(s)//k+1)]
        if not L[-1]:
            L.pop()
        else:
            L[-1] = L[-1]+fill*(k-len(L[-1]))
        return L