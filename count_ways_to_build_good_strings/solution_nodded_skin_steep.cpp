class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        int res=0, mod=1000000007;
        for (int i=1; i<=high; i++)
        {
            int a = i-zero, b = i-one;
            if (a>=0) dp[i]+=dp[a]%mod;
            dp[i]%=mod;
            if (b>=0) dp[i]+=dp[b]%mod;
            dp[i]%=mod;
            // cout << i << a << b << dp[i]<<endl;
            if (i>=low) res+=dp[i];
            res%=mod;
        }
        return res;
    }
};