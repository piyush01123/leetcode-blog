class Solution {
    vector<vector<int>> memo;
public:
    int util(int i, int j, int m, int n, vector<vector<int>>&grid)
    {
        if (i==m-1 && j==n-1) return 1;
        if (i==m || j==n || grid[i][j]) return -1;
        if (memo[i][j]!=-1) return memo[i][j];
        int res = 0;
        int a = util(i+1, j, m, n, grid);
        int b = util(i, j+1, m, n, grid);
        if (a!=-1) res += a;
        if (b!=-1) res += b;
        return memo[i][j] = res;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        memo = vector<vector<int>>(m, vector<int>(n,-1));
        return util(0,0,m,n,obstacleGrid);
    }
};