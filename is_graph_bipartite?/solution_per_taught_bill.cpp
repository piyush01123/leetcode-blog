class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<int>&colors, int cur)
    {
        bool res = true;
        for (int nbd: graph[cur]) 
        if (colors[nbd]==colors[cur]) return false;
        else if (colors[nbd]==0)
        {
            colors[nbd] = -colors[cur];
            res &= dfs(graph, colors, nbd);
        }
        return res;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size(), uncolored=0, white=1, black=-1;
        vector<int> colors(n, uncolored);
        for (int i=0; i<n; i++) if (colors[i]==uncolored)
        {
            colors[i] = white;
            bool cur = dfs(graph, colors, i);
            if (!cur) return false;
        }
        return true;
    }
};