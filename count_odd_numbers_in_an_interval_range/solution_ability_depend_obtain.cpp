class Solution {
public:
    int countOdds(int low, int high) 
    {
        int res = (high-low)/2;
        if (low%2==0 && high%2==0) return res;
        return 1+res;
    }
};