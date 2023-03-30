class Solution {
public:
    int climbStairs(int n) {
        if (n<4) return n;
        int a=1, b=2, b_old;
        for (int i=2; i<n; i++)
        {
            b_old=b;
            b = a+b;
            a = b_old;
        }
        return b;
    }
};