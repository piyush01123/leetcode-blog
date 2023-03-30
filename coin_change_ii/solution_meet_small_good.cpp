class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n,0));
        for (int j=0; j<n; j++) dp[0][j]=1;
        for (int i=1; i<=amount; i++)
        {
            for (int j=0; j<n; j++)
            {
                int x,y;
                if (j>0) x = dp[i][j-1];
                else x = 0;
                if (i-coins[j]>=0) y = dp[i-coins[j]][j];
                else y = 0;
                dp[i][j] = x+y;
            }
        }
        return dp[amount][n-1];
    }
};