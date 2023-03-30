class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousands {"","M","MM","MMM"};
        vector<string> hundreds  {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> tens      {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> ones      {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        int th,hu,te;
        th = num/1000, num = num%1000;
        hu = num/100, num = num%100;
        te = num/10, num = num%10;
        return thousands[th]+hundreds[hu]+tens[te]+ones[num];     
    }
};