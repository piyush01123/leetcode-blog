class Solution {
public:
    int maxProfit(int K, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(K+1,0));
        for (int k=1; k<=K; k++)
        {
            int minPrice = prices[0];
            for (int i=1; i<n; i++)
            {
                int price = prices[i];
                minPrice = min(minPrice, price-dp[i-1][k-1]);
                dp[i][k] = max(dp[i-1][k], price-minPrice);
            }
        }
        return dp[n-1][K];        
    }
};