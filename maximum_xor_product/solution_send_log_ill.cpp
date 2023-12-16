typedef long long int ll;
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) 
    {
        int mod=1e9+7;
        ll adash = 0, bdash = 0;
        for (ll i=49; i>=n; i--)
        {
            int abit = (a>>i)&1, bbit = (b>>i)&1;
            if (abit) adash |= (1LL<<i);
            if (bbit) bdash |= (1LL<<i);
        }
        for (ll i=n-1; i>=0; i--)
        {
            int abit = (a>>i)&1, bbit = (b>>i)&1;
            if (abit == bbit)
            {
                adash |= (1LL<<i);
                bdash |= (1LL<<i);
            }
            else
            {
                if (adash<bdash) adash |= (1LL<<i);
                else bdash |= (1LL<<i);
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