class Solution {
    int mod = 1e9+7;
public:
    int dfs(int i, int n, int p, vector<int>&groups, vector<int>&profits, int minProfit, vector<vector<vector<int>>>&dp)
    {
        if (i==groups.size()) return (p>=minProfit)?1:0;
        if (dp[i][n][p]!=-1) return dp[i][n][p];
        int cur = 0;
        cur += dfs(i+1, n, p, groups, profits, minProfit, dp)   %mod;
        if (n-groups[i]>=0)
            cur += dfs(i+1, n-groups[i], min(minProfit, p+profits[i]), groups, profits, minProfit, dp)\
                    %mod;
        return dp[i][n][p] = cur%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        vector<vector<vector<int>>> dp(group.size()+1, vector<vector<int>>(n+1, \
                                                    vector<int>(minProfit+1,-1)));
        return dfs(0, n, 0, group, profit, minProfit, dp);
    }
};

