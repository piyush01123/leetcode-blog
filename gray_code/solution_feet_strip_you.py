class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n==1: return [0,1]
        last = self.grayCode(n-1)
        return last + [item + (1<<n-1) for item in last[::-1]]