class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        int sign = ((dividend>0)^(divisor>0)) ? -1 : +1;
        long dvd = labs(dividend), dvs = labs(divisor), res=0;
        while (dvd >= dvs)
        {
            long temp = dvs, m=1;
            while (dvd >= (temp<<1))
            {
                m <<= 1;
                temp <<= 1;
            }
            res += m;
            dvd -= temp;
        }
        return res*sign;
    }
};
