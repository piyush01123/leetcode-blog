class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n==1: return [0,1]
        prev = self.grayCode(n-1)
        return prev + [2**(n-1)+i for i in prev[::-1]]