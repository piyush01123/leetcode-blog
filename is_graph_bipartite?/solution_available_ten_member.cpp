class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size(), uncolored=0, white=1, black=-1;
        vector<int> colors(n, 0);
        queue<int> Q;
        for (int i=0; i<n; i++) if(colors[i]==uncolored)
        {
            colors[i] = white;
            Q.push(i);
            while(!Q.empty())
            {
                for (int i=Q.size(); i>0; i--)
                {
                    int cur = Q.front();
                    Q.pop();
                    for (int nbd: graph[cur])
                    if (colors[nbd]==colors[cur]) return false;
                    else if (colors[nbd]==uncolored)
                    {
                        colors[nbd] = -colors[cur];
                        Q.push(nbd);
                    }
                }
            }
        }
        return true;
    }
};