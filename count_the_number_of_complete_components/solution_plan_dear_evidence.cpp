class Solution {
public:
    void dfs(vector<vector<int>>&G, int u, unordered_set<int>&component, int &ctr)
    {
        component.insert(u);
        ctr += G[u].size();
        for (int v: G[u]) if (!component.count(v)) dfs(G, v, component, ctr);
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
        int ctr=0, res=0;
        for (int i=0; i<n; i++)
        {
            if (visited.count(i)) continue;
            dfs(G, i, component, ctr);
            ctr/=2; int nc=component.size();
            if (ctr==nc*(nc-1)/2) res++;
            visited.insert(component.begin(),component.end());
            component.clear(); ctr=0;
        }
        return res;
    }
};