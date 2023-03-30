class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n==1: return [0,1]
        if n==2: return [0,1,3,2]
        l = self.grayCode(n-1)
        l2 = [bin(i)[2:] for i in l]
        l3 = ['0'*(n-1-len(i))+i for i in l2]
        m = [int('1'+i,2) for i in l3] 
        return l+m[::-1]