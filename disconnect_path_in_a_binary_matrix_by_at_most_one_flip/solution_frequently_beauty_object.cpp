class Solution {
public:
    int reached = 0;
    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid)
    {
        if (reached==1) return;
        grid[i][j] = 0;
        if (i==m-1 && j==n-1)
        {
            reached = 1;
            return;
        }
        if (i+1<m && grid[i+1][j]==1) dfs(i+1, j, m, n, grid);
        if (j+1<n && grid[i][j+1]==1) dfs(i, j+1, m, n, grid);
        grid[i][j] = 0;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        dfs(0,0,m,n, grid);
        if (reached==0) return true;
        // for(auto row: grid){for(int i: row)cout<<i<<',';cout<<endl;}
        if (reached==1)
        {
            reached = 0;
            grid[0][0] = 1;
            grid[m-1][n-1] = 1;
        }
        dfs(0,0,m,n, grid);
        return (reached==0);
    }
};