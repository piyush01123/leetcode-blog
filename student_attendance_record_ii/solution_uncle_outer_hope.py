class Solution:
    def checkRecord(self, n: int) -> int:
        if n==1: return 3;
        if n==2: return 8;
        pp0,pl0,lp0,ll0,pp1,pl1,lp1,ll1,pa1,ap1,la1,al1 = 1,1,1,1,0,0,0,0,1,1,1,1
        for _ in range(n-2):
            pp0,pl0,lp0,ll0,pp1,pl1,lp1,ll1,pa1,ap1,la1,al1 = pp0+lp0, pp0+lp0, \
            pl0+ll0, pl0, pp1+lp1+ap1, pp1+lp1+ap1, pl1+ll1+al1, pl1+al1, \
            pp0+lp0, pa1+la1, pl0+ll0, pa1+la1
            pp0,pl0,lp0,ll0,pp1,pl1,lp1,ll1,pa1,ap1,la1,al1 = \
            pp0%1000000007,pl0%1000000007,lp0%1000000007,ll0%1000000007, \
            pp1%1000000007,pl1%1000000007,lp1%1000000007,ll1%1000000007, \
            pa1%1000000007,ap1%1000000007,la1%1000000007,al1%1000000007
        return sum([pp0,pl0,lp0,ll0,pp1,pl1,lp1,ll1,pa1,ap1,la1,al1])%1000000007