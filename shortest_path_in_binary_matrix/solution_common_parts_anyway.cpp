class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if (grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        vector<vector<int>> dirs {{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};
        queue<pair<int,int>> Q;
        Q.push({0,0});
        grid[0][0] = 1;
        int ctr = 1;
        while (!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                auto rowCol = Q.front();
                Q.pop();
                int row=rowCol.first, col=rowCol.second;
                if (row==n-1 && col==n-1) return ctr;
                for (auto dir: dirs)
                {
                    int nbdRow = row+dir[0], nbdCol = col+dir[1];
                    if (nbdRow>=0 && nbdRow<n && nbdCol>=0 && nbdCol<n && grid[nbdRow][nbdCol]==0)
                    {
                        Q.push({nbdRow,nbdCol});
                        grid[nbdRow][nbdCol] = 1;
                    }
                }
            }
            ctr++;
        }
        return -1;
    }
};