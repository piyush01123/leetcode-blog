class Solution {
    vector<bool> visited;
    vector<vector<int>> G;
public:
    void dfs(int u)
    {
        visited[u] = true;
        for(int v: G[u]) if(!visited[v]) dfs(v);
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size(), ctr = 0;
        G.resize(n);
        visited.resize(n,false);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(isConnected[i][j])
        {
            G[i].push_back(j);
            G[j].push_back(i);
        }
        for(int i=0; i<n; i++) if(!visited[i]) 
        {
            dfs(i);
            ctr++;
        }
        return ctr;
    }
};