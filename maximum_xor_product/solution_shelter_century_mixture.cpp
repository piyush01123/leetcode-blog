class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) 
    {
        long long adash=0, bdash=0, mod=1e9+7;
        for (long long i=n; (1LL<<(long long)i)<=a; i++)
        {
            int abit = (a>>i)&1;
            if (abit) adash |= (1LL<<(long long)i);
        }
        for (long long i=n; (1LL<<(long long)i)<=b; i++)
        {
            int bbit = (b>>i)&1;
            if (bbit) bdash |= (1LL<<(long long)i);
        }
        for (long long i=n-1; i>=0; i--)
        {
            int abit = (a>>i)&1, bbit = (b>>i)&1;
            if (abit == bbit)
            {
                adash |= (1LL<<(long long)i);
                bdash |= (1LL<<(long long)i);
            }
            else
            {
                if (adash<bdash) adash |= (1LL<<(long long)i);
                else bdash |= (1LL<<(long long)i);
            }
        }
        return ((adash % mod) * (bdash % mod))%mod;       
    }
};

/*
1100
0101
4
1-0,8
0-4,12
1-6,14
1-7,14
*/