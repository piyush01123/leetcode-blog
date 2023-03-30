class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        res = ''
        maxval = -1
        for a,b,c,d in itertools.permutations(arr):
            hh,mm = 10*a+b, 10*c+d
            if hh>=0 and hh<=23 and mm>=0 and mm<=59:
                hh_str, mm_str = str(hh), str(mm)
                if len(hh_str)==1: hh_str='0'+hh_str
                if len(mm_str)==1: mm_str='0'+mm_str
                out = hh_str+':'+mm_str
                val = hh*60+mm
                # print(out,val)
                if val > maxval:
                    maxval = val
                    res = out    
        return res
