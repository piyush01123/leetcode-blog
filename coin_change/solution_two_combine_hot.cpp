class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n,-1));
        for (int j=0; j<n; j++) dp[0][j] = 0;
        for (int i=1; i<=amount; i++)
        {
            for (int j=0; j<n; j++)
            {
                int x, y;
                if (j>0 && dp[i][j-1]>=0) x = dp[i][j-1];
                else x = 0;
                if (i-coins[j]>=0 && dp[i-coins[j]][j]>=0) y = dp[i-coins[j]][j]+1;
                else y = 0;
                if (x&&y) dp[i][j] = min(x,y);
                else if (x) dp[i][j] = x;
                else if (y) dp[i][j] = y;
                else dp[i][j] = -1;
            }
        }
        return dp[amount][n-1];
    }
};