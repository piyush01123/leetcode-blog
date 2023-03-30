class Solution {
public:
    int comb(int n, int r)
    {
        vector<vector<int>> dp(n+1, vector<int>(r+1,0));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++)
            for (int j=0; j<=r; j++)
                dp[i][j] = dp[i-1][j] + ((j>0)?dp[i-1][j-1]:0) ;
        return dp[n][r];
    }
    
    int uniquePaths(int m, int n) 
    {
        if (m==1 || n==1) return 1;
        return (m<n) ? comb(m+n-2, m-1) : comb(m+n-2, n-1);
    }
};