class Solution {
    vector<bool> visited;
    vector<vector<int>> G;
public:
    void bfs(int u)
    {
        queue<int> Q;
        Q.push(u);
        while(!Q.empty())
        {
            for(int i=Q.size(); i>0; i--)
            {
                int cur = Q.front();
                Q.pop();
                visited[cur] = true;
                for(int nbd: G[cur]) if(!visited[nbd]) Q.push(nbd);
            }
        }
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
            bfs(i);
            ctr++;
        }
        return ctr;
    }
};