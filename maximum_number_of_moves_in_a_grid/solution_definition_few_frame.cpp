class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&visited, int m, int n)
    {
        if (j==n-1) return 0;
        int res=0;
        visited[i][j] = true;
        for (int ii=max(i-1,0); ii<=min(m-1,i+1); ii++)
            if (grid[ii][j+1]>grid[i][j] && !visited[ii][j+1])
                res = max(res, 1+dfs(ii,j+1,grid,visited,m,n));
        return res;
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for (int i=0; i<m; i++)
        {
            res = max(res, dfs(i, 0, grid, visited, m, n));
            if (res==n-1) return res;
        }
        return res;
    }
};