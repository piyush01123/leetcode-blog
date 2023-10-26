class Solution {
public:
    double distance(double x1, double y1, double x2, double y2)
    {
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
    int dfs(vector<vector<int>>&G, int cur, unordered_set<int>&visited)
    {
        visited.insert(cur);
        int res=1;
        for(int nbd: G[cur]) if (!visited.count(nbd)) res+=dfs(G, nbd, visited);
        return res;
    }
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n=bombs.size();
        vector<vector<int>>G(n);
        for (int i=0; i<n; i++)
        {
            double xi=bombs[i][0], yi=bombs[i][1], ri=bombs[i][2];
            for (int j=i+1; j<n; j++)
            {
                double xj=bombs[j][0], yj=bombs[j][1], rj=bombs[j][2];
                if (distance(xi,yi,xj,yj)<=ri*ri) G[i].push_back(j);
                if (distance(xj,yj,xi,yi)<=rj*rj) G[j].push_back(i);
            }
        }
        int res=0;
        for(int i=0; i<n; i++)
        {
            unordered_set<int>visited;
            res=max(res, dfs(G,i,visited));
        }
        return res;
    }
};