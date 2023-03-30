class Solution:
    def romanToInt(self, s: str) -> int:
        rom2int = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        return sum(rom2int[c] for c in s.replace("IV","IIII").replace("IX","VIIII").replace("XL","XXXX").replace("XC","LXXXX").replace("CD","CCCC").replace("CM","DCCCC"))