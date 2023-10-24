class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size(), res=0;
        queue<pair<int,int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++) 
        {
            Q.push({i,0});
            visited[i][0] = true;
        }
        while(!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                int curY=Q.front().first, curX=Q.front().second;
                if (curX==n-1) return n-1;
                Q.pop();
                for (int nbdY=max(0,curY-1); nbdY<=min(m-1,curY+1); nbdY++)
                {
                    int nbdX = curX+1;
                    if (grid[nbdY][nbdX]>grid[curY][curX] && !visited[nbdY][nbdX]) 
                    {
                        visited[nbdY][nbdX] = true;
                        Q.push({nbdY,nbdX});
                    }

                }
            }
            res++;
        }
        return res-1;
    }
};