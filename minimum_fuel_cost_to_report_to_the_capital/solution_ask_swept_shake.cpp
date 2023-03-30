class Solution 
{
public:
    long long fuel = 0;
    long long dfs(vector<vector<int>>&G, int node, int parent, int seats)
    {
        int numRep = 1;
        for (int child: G[node])
        {
            if (child==parent) continue;
            numRep += dfs(G, child, node, seats);
        }
        if (node!=0) fuel += ceil((double)numRep/seats);
        return numRep;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n = roads.size()+1;
        vector<vector<int>> G(n);
        for (auto &road: roads)
        {
            int u=road[0], v=road[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(G, 0, -1, seats);
        return fuel;
    }
};