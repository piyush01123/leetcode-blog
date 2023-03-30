class Solution:
    def intToRoman(self, num: int) -> str:
        thousands= ["","M","MM","MMM"]
        hundreds = ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"]
        tens =     ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"]
        ones =     ["","I","II","III","IV","V","VI","VII","VIII","IX"]
        th, num = num//1000, num%1000
        hu, num = num//100, num%100
        te, num = num//10, num%10
        return thousands[th]+hundreds[hu]+tens[te]+ones[num]
