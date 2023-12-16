class Solution 
{
    int mod=1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int res = 0;
        vector<int>dp(high+1,0);
        dp[0]=1; //len=0 --> 1 string ""
        for (int i=1; i<=high; i++)
        {
            dp[i] += (i-zero>=0) ? dp[i-zero]%mod : 0;
            dp[i] %= mod;
            dp[i] += (i-one>=0) ? dp[i-one]%mod : 0;
            dp[i] %= mod;
            if (i>=low) res+= dp[i];
            res %= mod;
        }
        return res;
    }
};