class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n==1: return [0,1]
        prev = self.grayCode(n-1)
        l = [bin(i)[2:] for i in prev]
        m = [int('1'+'0'*(n-1-len(i))+i,2) for i in l] 
        return prev+m[::-1]