class Solution {
public:
    bool powerOf2(int n)
    {
        return ((n&n-1)==0);
    }
    int minOperations(int n) 
    {
        if (n==0) return 0;
        if (powerOf2(n)) return 1;
        int msb = 0;
        int nc = n;
        // cout << nc << endl;
        while(nc){nc/=2; msb++;} msb--;
        int m = (1<<msb), M = (1<<(msb+1));
        // cout << m << ',' << M << endl;
        return 1 + min(minOperations(n-m), minOperations(M-n));
    }
};