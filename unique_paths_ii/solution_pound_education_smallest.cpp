class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<vector<int>> res(m, vector<int>(n,0));
        int r=0,c=0;
        while(r<m && obstacleGrid[r][0]==0) {res[r][0]=1; r++;}
        while(c<n && obstacleGrid[0][c]==0) {res[0][c]=1; c++;}
        for(int i=r; i<m; i++) res[i][0]=0;
        for(int j=c; j<n; j++) res[0][j]=0;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if (obstacleGrid[i][j]){res[i][j]=0; continue;}
                res[i][j] = res[i-1][j]+res[i][j-1];
            }
        }
        return res[m-1][n-1];        
    }
};