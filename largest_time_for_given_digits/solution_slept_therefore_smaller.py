class Solution:
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
#         H = dict(zip(range(10), [0]*10))
#         for a in A:
#             H[a] += 1
#         if H[0] + H[1] + H[2] == 0:
#             return ""
#         if H[2]>0:
#             h1 = 2
#             H[2] -= 1
        
#         if H[1]>0:
            
#         h1 = 0
        

        # nums = []
        # for i in range(len(A)):
        #     for j in range(i+1, len(A)):
        #         nums.append(10*A[i] + A[j])
        #         nums.append(10*A[j] + A[i])
        # print(nums)
        # H = []
        # M = []
        # for num in nums:
        #     if num <= 23:
        #         H.append(num)
        #     if num<= 59:
        #         M.append(num)
        # print(H, M)
        # if len(H) > 0 and len(M) > 0:
        #     return "%s:%s" %(max(H), max(M))
        # return ""
        import itertools
        perms = itertools.permutations(A)
        T = {}
        for p in perms:
            h = 10*p[0] + p[1]
            m = 10*p[2] + p[3]
            print(h, m)
            if h<= 23 and m<= 59:
                if h not in T:
                    T[h] = [m]
                else:
                    T[h].append(m)
        print(T)
        if len(T) > 0:
            h_max = max(T)
            m_max = max(T[h_max])
            if h_max//10 == 0:
                h_max = "0" + str(h_max)
            if m_max//10 == 0:
                m_max = "0" + str(m_max)
                
            return "%s:%s" %(h_max, m_max)
        return ""

        
        
            
        