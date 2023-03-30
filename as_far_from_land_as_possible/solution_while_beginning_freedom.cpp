class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size(), distance=-1;
        queue<pair<int,int>> Q;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++)
        if (grid[i][j]) Q.push({i,j});
        if (Q.empty()||Q.size()==n*n) return -1;
        vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        while (!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                auto cell = Q.front();
                Q.pop();
                for (auto &dir: directions)
                {
                    int x = cell.first+dir.first;
                    int y = cell.second+dir.second;
                    if (x<0||x>=n||y<0||y>=n) continue;
                    if (grid[x][y]==0)
                    {
                        grid[x][y] = 1;
                        Q.push({x,y});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};