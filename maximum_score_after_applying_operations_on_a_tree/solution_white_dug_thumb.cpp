class Solution {
    vector<vector<long long>> dp;
public:
    long long dfs(vector<vector<int>>&G, vector<int>&values, int u, int par, bool skipped)
    {
        if (dp[u][skipped]!=-1) return dp[u][skipped];
        bool isLeaf = true;
        for (int v: G[u]) if(v==par) continue; else isLeaf=false;
        if(skipped)
        {
            long long cur=values[u];
            for (int v: G[u]) if (v==par) continue; else cur+=dfs(G,values,v,u,true);
            return dp[u][skipped] = cur;
        }
        else
        {
            if (isLeaf) return 0;
            long long a=0, b=values[u];
            for (int v: G[u])
            {
                if (v==par) continue; 
                a += dfs(G,values,v,u,true);
                b += dfs(G,values,v,u,false);
            }
            return dp[u][skipped] = max(a,b);
        }
        return -1;        
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>> G(n);
        for (auto &edge: edges)
        {
            int u=edge[0], v=edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dp.resize(n,vector<long long>(2,-1));
        return dfs(G, values, 0, -1, false);
    }
};