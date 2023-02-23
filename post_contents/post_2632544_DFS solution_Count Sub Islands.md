Run DFS for entire table. Create a vector for each island in `grid2`. If all the cells are also 1 in `grid1`, then this island is a sub-island.
```
class Solution {
public:
    void dfs(vector<vector<int>>&grid, int i, int j, int m, int n, vector<pair<int,int>>&isle)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1) return;
        grid[i][j] = 2;
        isle.push_back({i,j});
        dfs(grid,i-1,j,m,n,isle);
        dfs(grid,i+1,j,m,n,isle);
        dfs(grid,i,j-1,m,n,isle);
        dfs(grid,i,j+1,m,n,isle);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), res=0;
        vector<vector<int>> cells;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid2[i][j]==1)
                {
                    vector<pair<int,int>> isle;
                    dfs(grid2,i,j,m,n,isle);
                    bool covered = true;
                    for (auto p: isle)
                    {
                        if (grid1[p.first][p.second] != 1)
                        {
                            covered = false;
                            break;
                        }
                    }
                    if (covered) res++;
                }
            }
        }
        return res;
    }
};
```