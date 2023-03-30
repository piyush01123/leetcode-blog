class Solution {
public:
    int getSum(int a, int b) 
    {
        uint c;
        while (b)
        {
            c = a&b;
            a = a^b;
            b = c<<1;
        }
        return a;
    }
};