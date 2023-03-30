class Solution {
public:
    string fractionToDecimal(long long nr, long long dr) 
    {
        if (nr==0) return "0";
        string res = "";
        if ((nr<0)^(dr<0)) res += '-';
        nr = abs(nr), dr=abs(dr);
        res += to_string(nr/dr);
        long long rem = nr%dr;
        if (rem==0) return res;
        res += '.';
        unordered_map<int,int> decimal;
        while (rem>0 && decimal.count(rem)==0)
        {
            decimal[rem] = res.length();
            rem *= 10;
            res += to_string(rem/dr);
            rem %= dr;
        }
        if (rem>0)
        {
            res.insert(decimal[rem], "(");
            res += ')';
        }
        return res;
    }
};