class Solution {
public:
    int playGame(vector<vector<int>>&grid, int i, int j, int m, int n)
    {
        if (i==m) return j;
        if (j<n-1 && grid[i][j]== 1 && grid[i][j+1]==-1) return -1;
        if (j>0   && grid[i][j]==-1 && grid[i][j-1]== 1) return -1;
        if (j==0 && grid[i][j] ==-1) return -1;
        if (j==n-1 && grid[i][j]==1) return -1;
        if (grid[i][j]==1) 
            return playGame(grid,i+1, j+1, m, n);
        return playGame(grid,i+1,j-1,m,n);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<int>res(n,0);
        for (int j=0; j<n; ++j)
            res[j] = playGame(grid,0,j,m,n);
        return res;
    }
};