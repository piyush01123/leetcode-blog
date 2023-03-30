class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        max_pens=total//cost1
        res=0
        for n_pen in range(max_pens+1):
            n_pencils = (total-n_pen*cost1)//cost2
            res += (n_pencils+1)
        return res