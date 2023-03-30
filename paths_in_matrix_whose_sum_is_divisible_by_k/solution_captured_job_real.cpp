class Solution {
public:
    void pv( vector<vector<vector<int>>> &V)
    {
        for (auto &vecvec:V) for(auto &vec: vecvec) 
        {for (int i: vec) cout<<i<<',';cout<<endl;}
    }
    int numberOfPaths(vector<vector<int>>& grid, int K) 
    {
        int m=grid.size(), n=grid[0].size(), mod=1000000007;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(K,0)));
        dp[0][0][grid[0][0]%K]++;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                for (int k=0; k<K; k++)
                {
                    if (i==0 && j==0) continue;
                    int a = ((j==0) ? 0 : dp[i][j-1][(K+k-grid[i][j]%K)%K] % mod);
                    int b = ((i==0) ? 0 : dp[i-1][j][(K+k-grid[i][j]%K)%K] % mod);
                    dp[i][j][k] = (a+b)%mod;
                }
        // pv(dp);
        return dp[m-1][n-1][0];
    }
};
