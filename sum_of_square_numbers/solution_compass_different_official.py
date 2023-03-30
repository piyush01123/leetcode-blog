class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        i=0
        H = set()
        while i*i<=c:
            H.add(i*i)
            if c-i*i in H:
                # print(i*i, c-i*i)
                return True
            else:
                pass
            i+=1
        return False
        
        
#         import numpy as np
#         low = 0
#         high = int(np.sqrt(c))
#         while low<=high:
#             mid = (low+high)//2
#             if mid*mid==c:
                
#                 return True

    # def judgeSquareSum(self, c):
    #     """
    #     :type c: int
    #     :rtype: bool
    #     """
    #     i=0
    #     while i*i<=c:
    #         j=0
    #         while i*i + j*j <=c:
    #             if i*i + j*j == c:
    #                 return True
    #             else:
    #                 pass
    #             j+=1
    #         i+=1
    #     return False