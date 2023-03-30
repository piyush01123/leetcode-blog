class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size(), uncolored=0, white=1, black=-1;
        vector<int> colors(n, uncolored);
        queue<int> Q;
        for (int i=0; i<n; i++)
        {
            if (colors[i]!=uncolored) continue;
            colors[i] = white;
            Q.push(i);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int v: graph[u])
                {
                    if (colors[v]==uncolored)
                    {
                        colors[v] = -colors[u];
                        Q.push(v);
                    }
                    else if (colors[v]==colors[u])
                        return false;
                }
            }
        }
        return true;
    }
};