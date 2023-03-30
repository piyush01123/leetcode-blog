class Solution {
public:
    int util(int r, int c, vector<vector<int>> &grid, int m, int n, unordered_set<int> &visited)
    {
        if (r<0 || r>=m || c<0 || c>=n) return 0;
        if (visited.count(n*r+c)>0 || grid[r][c]==0) return 0;
        visited.insert(n*r+c);
        return 1 + util(r-1,c,grid,m,n,visited) + util(r+1,c,grid,m,n,visited) + \
                   util(r,c-1,grid,m,n,visited) + util(r,c+1,grid,m,n,visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        unordered_set<int> visited;
        for (int r=0; r<m; r++)
            for (int c=0; c<n; c++)
                res = max(res, util(r,c,grid,m,n,visited));
        return res;
    }
};