- Create a `dp` matrix of size (nxn)
- Copy last row of `matrix` to last row of `dp`
- Iteratively go up from `r=n-2` to `r=0`. For element `(r,c)` the expression we have is: `dp[r,c] = min(dp[r+1,c-1], dp[r+1,c], dp[r+1,c+1])`
- For `c=0` and `c=n-1` take min of only two elements rather than 3. These are left and right edges
- After reaching top row, check which element in top row is the minimum.
- Done!


```
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
```

BTW, this algorithm is used in a smart image resizing method known as [Seam Carving](https://en.wikipedia.org/wiki/Seam_carving).