class Solution {
public:
    long long smallestNumber(long long num) {
        if (num==0) return 0;
        int sign=(num>0)?1:-1;
        num = sign*num;
        vector<int>digits;
        while(num){digits.push_back(num%10); num/=10;}
        sort(digits.begin(), digits.end());
        long long res=0;
        if (sign<0)
        {
            reverse(digits.begin(), digits.end());
            for (int d: digits) res = 10*res+d;
            return -res;
        }
        else
        {
            int zeros=0;
            while (digits[zeros]==0) zeros++;
            res = digits[zeros];
            for (int i=0; i<zeros; i++) res*=10;
            for (int i=zeros+1; i<digits.size(); i++) res = 10*res+digits[i];
            return res;
        }
    }
};