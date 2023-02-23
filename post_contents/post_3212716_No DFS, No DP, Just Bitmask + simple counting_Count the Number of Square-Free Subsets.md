We just count all valid bitmasks.
```
class Solution {
public:
    int mod = 1000000007;
    vector<int> primes = vector<int>{2,3,5,7,11,13,17,19,23,29};
    int getMask(int n)
    {
        if (n==1) return 0;
        int mask = 0;
        for (int i=0; i<primes.size();i++)
        {
            int ctr = 0;
            while (n%primes[i]==0)
            {
                n /= primes[i];
                ctr ++;
            }
            if (ctr>=2) return -1;
            if(ctr) mask |= (1<<i);
        }
        return mask;
    }
    int squareFreeSubsets(vector<int>& nums) 
    {
        unordered_map<long long,long long> H;
        for (int n: nums)
        {
            unordered_map<long long,long long> Hcopy = H;
            int mask = getMask(n);
            if (mask==-1) continue;
            for (auto [k,v]: Hcopy) if ((k & mask)==0) H[ (k|mask) ] = (H[k|mask]%mod + v%mod)%mod;
            H[mask]++;
        }
        long long res = 0;
        for (auto [k,v]: H) res += v;
        return (int)(res%mod);
    }
};
```