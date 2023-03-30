class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n==1: return '0'
        rev = {'0':'1', '1': '0'}
        curr = '0'
        for i in range(n-1):
            curr = curr + '1' + ''.join([rev[j] for j in curr[::-1]])
        return curr[k-1]