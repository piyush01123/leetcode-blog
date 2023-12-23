class Solution {
public:
    void dfs(vector<vector<int>>&G, int u, unordered_set<int>&component)
    {
        component.insert(u);
        for (int v: G[u]) if (!component.count(v)) dfs(G, v, component);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n);
        for(auto &edge: edges)
        {
            int u=edge[0], v=edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        unordered_set<int> visited, component;
        int res=0;
        for (int i=0; i<n; i++)
        {
            if (visited.count(i)) continue;
            dfs(G, i, component);
            bool isComplete = true;
            for (int node: component)
            {
                if (G[node].size()!=component.size()-1)
                {
                    isComplete = false;
                    break;
                }
            }
            res += isComplete;
            visited.insert(component.begin(),component.end());
            component.clear();
        }
        return res;
    }
};