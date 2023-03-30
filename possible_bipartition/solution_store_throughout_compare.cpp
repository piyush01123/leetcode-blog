class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> G = vector<vector<int>>(n, vector<int>{});
        for (auto &p: dislikes)
        {
            int a=p[0]-1, b=p[1]-1;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int uncolored=0, white=1, black=-1;
        vector<int> colors = vector<int>(n,uncolored);
        queue<int> Q;
        for (int i=0; i<n; i++)
        {
            if (colors[i]!=uncolored) continue;
            colors[i] = white;
            Q.push(i);
            while (!Q.empty())
            {
                int cur = Q.front();
                Q.pop();
                for (int adj: G[cur])
                {
                    if (colors[adj]==uncolored)
                    {
                        colors[adj]=-colors[cur];
                        Q.push(adj);
                    }
                    if (colors[adj]==colors[cur]) return false; 
                }
            }
        }
        return true;
    }
};