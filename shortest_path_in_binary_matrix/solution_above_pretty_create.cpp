class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if (grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        if (n==1 && m==1) return grid[0][0]==0;
        vector<pair<int,int>> neighbors{{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};
        queue<pair<int,int>> Q;
        Q.push({0,0});
        grid[0][0]=1;
        while (!Q.empty())
        {
            auto u=Q.front();
            Q.pop();
            int x=u.first, y=u.second;
            if (x==n-1 && y==m-1) return grid[x][y];
            for (auto neighbor: neighbors)
            {
                int dx=neighbor.first, dy=neighbor.second;
                int nx=x+dx, ny=y+dy;
                if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0)
                {
                    Q.push({nx,ny});
                    grid[nx][ny]=grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};