class Solution {
public:
    int totalMoney(int n) 
    {
        int weeks = n/7, days = n%7;
        return 28*weeks + 7*weeks*(weeks-1)/2 + days*(days+1)/2 + days*weeks;
        return -1;
    }
};