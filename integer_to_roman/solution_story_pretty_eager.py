class Solution:
    def intToRoman(self, num: int) -> str:
        s=""
        values = {v: s for s,v in zip("MDCLXVI", [1000,500,100,50,10,5,1])}
        for value,symbol in values.items():
            quot,rem = num//value, num%value
            s += symbol*quot
            num = rem
        s = s.replace("DCCCC", "CM").replace("CCCC", "CD")
        s = s.replace("LXXXX", "XC").replace("XXXX", "XL")
        s = s.replace("VIIII", "IX").replace("IIII", "IV")
        return s
