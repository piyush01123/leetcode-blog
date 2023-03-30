class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int> colors = vector<int>(V,0);
        queue<int> Q;

        for (int i=0; i<V; i++)
        {
            if (colors[i]!=0) continue;
            colors[i] = 1;
            Q.push(i);
            while(!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int v: graph[u])
                {
                    if (colors[v]==0)
                    {
                        colors[v] = -colors[u];
                        Q.push(v);
                    }
                    else
                        if (colors[v]==colors[u])
                            return false;
                }
            }
        }
        return true;
    }
};