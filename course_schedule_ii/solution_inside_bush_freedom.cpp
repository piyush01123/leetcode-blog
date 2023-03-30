// Colors: 0-Not visited, 1-visited and done, 2-visiting and recursion going on
class Solution {
    bool possible = true;
    int white = 0, grey=1, black=2;
public:
    void dfs(unordered_map<int,vector<int>> &G, vector<int> &seq, vector<int> &colors, int &u)
    {
        if (!possible) return;
        colors[u] = grey;
        for (int v: G[u])
        {
            if (colors[v]==white)
                dfs(G, seq, colors, v);
            else if (colors[v]==grey)
            {
                possible = false;
                return;
            }
        }
        seq.push_back(u);
        colors[u] = black;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> G;
        vector<int> colors(n, white);
        vector<int> seq;
        
        for (auto p: prerequisites)
            G[p[1]].push_back(p[0]);
        
        for (int u=0; u<n; u++)
            if (colors[u]==white)
                dfs(G,seq,colors,u);
       if (!possible) return {};
        reverse(seq.begin(),seq.end());
        return seq;
    }
};