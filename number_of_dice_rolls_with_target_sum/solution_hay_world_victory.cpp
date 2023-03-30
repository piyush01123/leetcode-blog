class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // dp[i,j] denotes numRollsToTarget(i,k,j)
        dp[0][0] = 1;
        int mod = 1000000007;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=target; j++)
            {
                int temp = 0;
                for (int p=1; p<=min(k,j); p++) 
                {
                    temp = (temp%mod) + ( dp[i-1][j-p]%mod);
                    temp %= mod;
                }
                dp[i][j] = temp;
            }
        }
        return dp[n][target];
    }
};
/*
numRollsToTarget(1,3):
DP[2,4]
0 - 0 1 2 3
    1 0 0 0
1-  0 1 2 3
    0 1 1 1
*/