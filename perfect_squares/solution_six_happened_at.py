class Solution:
    def numSquares(self, n: int) -> int:
        A = [0,1]
        for i in range(2,n+1):
            options = []
            j = 1
            while True:
                k = j*j
                if k > i:
                    break
                if k==i:
                    options.append(1)
                    break
                options.append(A[k]+A[i-k])                
                j += 1
            A.append(min(options))
        return A[-1]