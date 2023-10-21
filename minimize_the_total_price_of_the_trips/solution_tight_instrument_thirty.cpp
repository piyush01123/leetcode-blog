class Solution {
public:
    void getContrib(vector<vector<int>>&G, vector<int>&contrib, vector<int>path, int cur, int dest, int par)
    {
        path.push_back(cur);
        if (cur==dest)
        {
            for (int node: path) contrib[node]++;
            return;
        }
        for (int nbd: G[cur])
        {
            if (nbd==par) continue;
            getContrib(G, contrib, path, nbd, dest, cur);
        }
        path.pop_back();
    }

    int dfs(vector<vector<int>>&G, vector<vector<int>>&memo, vector<int>&contrib, vector<int>& prices, int cur, int par, bool parHalved)
    {
        if (memo[cur][parHalved]!=-1) return memo[cur][parHalved];
        int resCurNotHalved = prices[cur]*contrib[cur];
        for (int nbd: G[cur]) if(nbd!=par) 
            resCurNotHalved += dfs(G, memo, contrib, prices, nbd, cur, false);
        if (parHalved) return memo[cur][true] = resCurNotHalved;
        int resCurHalved = prices[cur]*contrib[cur]/2;
        for (int nbd: G[cur]) if(nbd!=par)
            resCurHalved += dfs(G, memo, contrib, prices, nbd, cur, true);
        return memo[cur][false] = min(resCurNotHalved, resCurHalved);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) 
    {
        vector<vector<int>> G(n, vector<int>{});
        for (auto &edge: edges)
        {
            int u=edge[0], v=edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> contrib(n, 0);
        for (auto &trip: trips)
        {
            int src=trip[0], dest=trip[1];
            vector<int> path;
            getContrib(G, contrib, path, src, dest, -1);
        }
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dfs(G, memo, contrib, price, 0, -1, false);
    }
};