class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int c=0; c<n; c++) dp[n-1][c] = matrix[n-1][c];
        for (int r=n-2; r>=0; r--)
        {
            for (int c=0; c<n; c++)
            {
                if (c==0) dp[r][c] = min(dp[r+1][c], dp[r+1][c+1]) + matrix[r][c];
                else if (c==n-1) dp[r][c] = min(dp[r+1][c], dp[r+1][c-1]) + matrix[r][c];
                else dp[r][c] = min(min(dp[r+1][c-1], dp[r+1][c]), dp[r+1][c+1]) + matrix[r][c];
            }
        }
        int res=INT_MAX;
        for (int c=0; c<n; c++) res = min(res, dp[0][c]);
        return res;
    }
};