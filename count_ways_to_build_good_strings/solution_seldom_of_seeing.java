class Solution 
{
    public int countGoodStrings(int low, int high, int zero, int one) 
    {
        int res=0, mod = 1000000007;
        int[] dp = new int[high+1];
        Arrays.fill(dp,0);
        dp[0] = 1;
        for(int i=1; i<=high; i++)
        {
            dp[i] += (i-zero>=0) ? dp[i-zero] : 0;
            dp[i] += (i-one>=0) ? dp[i-one] : 0;
            dp[i] %= mod;
            if (i>=low) res += dp[i];
            res %= mod;
        }
        return res;
    }
}