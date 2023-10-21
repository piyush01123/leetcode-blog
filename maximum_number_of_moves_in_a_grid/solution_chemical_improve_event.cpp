class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid, int m, int n, vector<vector<int>>&A)
    {
        if (A[i][j]!=-1) return A[i][j];
        if (j==n-1) return 0;
        int a = (i>0 && grid[i-1][j+1]>grid[i][j]) ? 1+dfs(i-1,j+1,grid,m,n,A) : 0;
        int b = (grid[i][j+1]>grid[i][j]) ? 1+dfs(i,j+1,grid,m,n,A) : 0;
        int c = (i<m-1 && grid[i+1][j+1]>grid[i][j]) ? 1+dfs(i+1,j+1,grid,m,n,A) : 0;
        return A[i][j] = max({a,b,c});
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        vector<vector<int>> A(m, vector<int>(n,-1));
        for (int i=0; i<m; i++)
        {
            res = max(res, dfs(i,0,grid,m,n,A));
            if (res==n-1) return res;
        }
        return res;
    }
};