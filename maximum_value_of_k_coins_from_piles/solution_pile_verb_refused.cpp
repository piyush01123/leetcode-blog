class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i=1; i<=n; i++)
        {
            for (int j=0; j<=k; j++)
            {
                dp[i][j] = dp[i-1][j]; // cur=0
                int curSum = 0;
                for (int cur=1; cur<=min((int)piles[i-1].size(),j); cur++)
                {
                    curSum += piles[i-1][cur-1];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-cur]+curSum);
                }
            }
        }
        return dp[n][k];
    }
};