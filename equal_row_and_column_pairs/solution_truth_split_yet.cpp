class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>&grid, int n)
    {
        vector<vector<int>>gridT(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)gridT[i][j]=grid[j][i];
        return gridT;
    }
    bool isEqual(vector<int>&a, vector<int>&b, int n)
    {
        for(int i=0;i<n;i++) if(a[i]!=b[i]) return false;
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid.size(), ctr=0;
        vector<vector<int>> gridT = transpose(grid,n);
        for(int i=0; i<n; i++)
        {
            vector<int> row = grid[i];
            for(int j=0; j<n; j++)
            {
                vector<int> col = gridT[j];
                if (isEqual(row,col,n)) ctr++;
            }
        }
        return ctr;
    }
};