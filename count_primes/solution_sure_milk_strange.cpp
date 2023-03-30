class Solution {
public:
    int countPrimes(int n)
    {
        if (n<2) return 0;
        vector<bool> prime(n+1,true);
        for (int p=2; p*p<=n; ++p)
        {
            if (!prime[p]) continue;
            for (int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
        
        int ctr = 0;
        for (int p=2; p<n; ++p) ctr += prime[p];
        return ctr;
    }
};