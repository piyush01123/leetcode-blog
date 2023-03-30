# class Solution:
#     def numDecodings(self, s):
#         # works but inefficient
#         """
#         :type s: str
#         :rtype: int
#         """
#         print('running with %s' %s)
#         if s.startswith('0') or s=='':
#             return 0
#         if len(s)==1:
#             if int(s) >= 1 and int(s) <= 9:
#                 return 1
#             else:
#                 # print('__0__')
#                 return 0
#         if len(s) ==2:
#             if int(s) >=10 and int(s) <= 26:
#                 if s.endswith('0'):
#                     return 1
#                 else:
#                     return 2
#             else:
#                 if s.endswith('0'):
#                     return 0
#                 else:
#                     return 1
#         if len(s) >= 2:
#             if int(s[:2])<=26:
#                 return self.numDecodings(s[2:]) + self.numDecodings(s[1:])
#             else:
#                 return self.numDecodings(s[1:])



class Solution:
    def numDecodings(self, s):
        # store helper(data, k) at memo[k]
        memo = [None]*(len(s)+1)
        print(memo)
        return self.helper(s, len(s), memo)
    def helper(self, data, k, memo):
        # k: we are looking only for last k letters of data.
        if k==0:
            return 1
        if data[len(data) - k] == '0':
            return 0
        if memo[k] != None:
            return memo[k]
        if k>=2 and int(data[len(data)-k:len(data)-k+2])<=26:
            memo[k] = self.helper(data, k-1, memo) + self.helper(data, k-2, memo)
            return memo[k]
        else:
            memo[k] = self.helper(data, k-1, memo)
            return memo[k]
        
        