class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i=1; i<=n; i++)
        {
            int ctr = 0;
            for (int root=1; root<=i; root++)
                ctr += dp[root-1]*dp[i-root];
            dp[i] = ctr;
        }
        return dp[n];
    }
};