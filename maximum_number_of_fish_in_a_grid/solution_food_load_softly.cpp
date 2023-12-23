class Solution {
public:
    int dfs(vector<vector<int>>&grid, int i, int j, int m, int n)
    {
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0) return 0;
        int fish = grid[i][j];
        grid[i][j] = 0;
        return fish+dfs(grid,i-1,j,m,n)+dfs(grid,i+1,j,m,n)+dfs(grid,i,j-1,m,n)+dfs(grid,i,j+1,m,n);
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        for(int i=0; i<m; i++) for (int j=0; j<n; j++) if (grid[i][j]) res=max(res, dfs(grid,i,j,m,n));;
        return res;
    }
};