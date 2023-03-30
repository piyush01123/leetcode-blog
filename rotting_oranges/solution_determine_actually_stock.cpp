class Solution {
public:
    bool notdone(vector<vector<int>>& grid)
    {
        for (auto row: grid)
            for (int cell: row)
                if (cell==1)
                    return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), ctr=0;
        while (notdone(grid))
        {
            vector<vector<int>> gridold = grid;
            for (int i=0; i<m; i++)
            {
                for (int j=0; j<n; j++)
                {
                    if (grid[i][j]==1 && ((i>0&&gridold[i-1][j]==2)||(i<m-1&&gridold[i+1][j]==2)||(j>0&&gridold[i][j-1]==2)||(j<n-1&&gridold[i][j+1]==2)))
                        grid[i][j] = 2;
                        
                }
            }
            // for (auto row: grid) for (int cell: row) cout<<cell<<',';cout<<endl;
            if (grid==gridold) return -1;
            gridold = grid;
            ctr++;
        }
        return ctr;
    }
};