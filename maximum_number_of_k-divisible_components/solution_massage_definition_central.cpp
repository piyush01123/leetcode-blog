class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, 
                                vector<int>& values, int k) 
    {
        int res=0;
        vector<vector<int>> G(n);
        vector<int> counts(n,0);
        for (auto vec: edges)
        {
            int u=vec[0], v=vec[1];
            G[u].push_back(v);
            G[v].push_back(u);
            counts[u]++;
            counts[v]++;
        }
        queue<int> Q;
        for (int i=0; i<n; i++) if (counts[i]<2) Q.push(i);
        while (!Q.empty())
        {
            int leaf = Q.front();
            Q.pop();
            if (values[leaf]%k == 0) res++;
            for (int adj: G[leaf])
            {
                counts[adj]--;
                values[adj] += values[leaf]%k;
                if (counts[adj]==1) Q.push(adj);
            }
        }
        return res;
    }
};