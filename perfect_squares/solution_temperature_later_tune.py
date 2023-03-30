class Solution:
    def numSquares(self, n: int) -> int:
        A = [0,1]
        for i in range(2,n+1):
            # print("I=",i)
            options = []
            j = 1
            while True:
                # print("J=", j)
                k = j*j
                if k > i:
                    # print("c1", i,j,k)
                    break
                if k==i:
                    # print("c2", i,j,k)
                    options.append(1)
                    break
                # print(k,i,j,A[k],A[i-k])
                options.append(A[k]+A[i-k])                
                j += 1
            # print(i,options)
            A.append(min(options))
        return A[-1]