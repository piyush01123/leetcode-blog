class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if (grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        vector<vector<int>> dirs {{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        Q.push({1,0,0});
        grid[0][0] = 1;
        dist[0][0] = 1;
        while (!Q.empty())
        {
            auto distRowCol = Q.top();
            Q.pop();
            int dis=distRowCol[0], row=distRowCol[1], col=distRowCol[2];
            for (auto dir: dirs)
            {
                int nbdRow = row+dir[0], nbdCol = col+dir[1];
                if (nbdRow>=0 && nbdRow<n && nbdCol>=0 && nbdCol<n && grid[nbdRow][nbdCol]==0 && dist[nbdRow][nbdCol]>dis+1)
                {
                    Q.push({dis+1,nbdRow,nbdCol});
                    grid[nbdRow][nbdCol] = 1;
                    dist[nbdRow][nbdCol] = dis+1;
                }
            }
        }
        return (dist[n-1][n-1]==INT_MAX)?-1:dist[n-1][n-1];
    }
};