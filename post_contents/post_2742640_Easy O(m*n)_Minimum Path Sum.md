The top row and leftmost column can simply be computed.
After that for any node, the answer can be either its upward neighbor + node value or its leftward neighbor + node value;
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> sumgrid(m, vector<int>(n,0));
        sumgrid[0][0] = grid[0][0];
        for (int i=1; i<m; i++) 
            sumgrid[i][0] = sumgrid[i-1][0] + grid[i][0];
        for (int j=1; j<n; j++)
            sumgrid[0][j] = sumgrid[0][j-1] + grid[0][j];
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                sumgrid[i][j] = min(sumgrid[i-1][j],sumgrid[i][j-1]) + grid[i][j];
        return sumgrid[m-1][n-1];
    }
};
```