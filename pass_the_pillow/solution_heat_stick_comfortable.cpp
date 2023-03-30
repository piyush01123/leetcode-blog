class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int K = 2*(n-1);
        int cur = time%K;
        if (cur<n) return 1+cur;
        else return K-cur+1;
    }
};