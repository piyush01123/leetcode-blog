class Solution:

    def maximumTime(self, time: str) -> str:
        hh, mm = time.split(':')
        h1, h2 = hh
        m1, m2 = mm
        if m2=='?':
            m2 = '9'
        if m1=='?':
            m1 = '5'
        if h1=='?':
            h1 = '2' if h2.isdigit() and int(h2)<=3 else '1'
        if h2=='?':
            h2 = '3' if h1=='2' else '9'
        if hh=='??':
            h1,h2='23'
        if mm=='??':
            m1,m2 = '59'


        return "{}{}:{}{}".format(h1,h2,m1,m2)
        
    
    
    
    
    
    
#     def maximumTime(self, time: str) -> str:
#         hh, mm = time.split(':')
#         if '?' not in hh:
#             hh_dash = hh
#         else:
#             for digit in range(9,-1,-1):
#                 hh_dash = hh.replace('?', str(digit))
#                 if int(hh_dash) in range(1,24):
#                     break
#         if '?' not in mm:
#             mm_dash = mm
#         else:
#             for digit in range(9,-1,-1):
#                 mm_dash = mm.replace('?', str(digit))
#                 if int(mm_dash) in range(1,60):
#                     break
        
#         return "{}:{}".format(hh_dash,mm_dash)


        

        

        
        

#     def validTime(self, time: str) -> bool:
#         hh, mm = time.split(':')
#         if not hh.isdigit() or not mm.isdigit():
#             raise ValueError("Bad string")
#         hh, mm = int(hh), int(mm)
#         if hh not in range(1,24) or mm not in range(1,60):
#             return False
#         return True

#     def maximumTime(self, time: str) -> str:
#         hh, mm = time.split(':')
#         if '?' not in hh or '?' not in mm:
#             for digit in range(9,-1,-1):
#                 time_string = time.replace('?', str(digit))
#                 if self.validTime(time_string):
#                     return time_string
#             return ValueError("Couldnt find anything")

        