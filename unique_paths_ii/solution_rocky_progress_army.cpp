class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        if (grid[0][0] || grid[m-1][n-1]) return 0;
        int r=0,c=1;
        while(r<m && grid[r][0]==0) {grid[r][0]=1; r++;}
        while(c<n && grid[0][c]==0) {grid[0][c]=1; c++;}
        for(int i=r; i<m; i++) grid[i][0]=0;
        for(int j=c; j<n; j++) grid[0][j]=0;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if (grid[i][j]){grid[i][j]=0; continue;}
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[m-1][n-1];        
    }
};