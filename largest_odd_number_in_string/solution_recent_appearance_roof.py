class Solution:
    def largestOddNumber(self, num: str) -> str:
        answer = -1
        n = len(num)
        found = 0
        for i in range(n-1,-1,-1):
            if int(num[i])%2==1:
                found = 1
                break
        if found==0:
            return ""
        return str(num[:i+1])

    
# class Solution:
#     def largestOddNumber(self, num: str) -> str:
#         answer = -1
#         n = len(num)
#         for i in range(n+1):
#             for j in range(i+1,n+1):
#                 number = int(num[i:j])
#                 if number>answer and number%2==1:
#                     answer = number
#         if answer==-1:
#             return ""
#         return str(answer)