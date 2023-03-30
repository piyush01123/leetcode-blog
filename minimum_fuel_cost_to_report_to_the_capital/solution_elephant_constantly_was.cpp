class Solution 
{
public:
    long long fuel = 0;
    void bfs(vector<vector<int>>&G, vector<int>&degree, int n, int seats)
    {
        vector<int> numRep(n, 1);
        queue<int> Q;
        for (int i=1; i<n; i++) if(degree[i]==1) Q.push(i);
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            fuel += ceil((double)numRep[node]/seats);
            for (int nbd: G[node])
            {
                degree[nbd]--;
                numRep[nbd]+=numRep[node];
                if (degree[nbd]==1 && nbd!=0) Q.push(nbd);
            }
        }
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n = roads.size()+1;
        vector<vector<int>> G(n);
        vector<int> degree(n,0);
        for (auto &road: roads)
        {
            int u=road[0], v=road[1];
            G[u].push_back(v);
            G[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        bfs(G, degree, n, seats);
        return fuel;
    }
};