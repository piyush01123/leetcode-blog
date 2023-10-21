class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> G(n);
        for (auto &edge: edges)
        {
            int u=edge[0], v=edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<int> Q;
        vector<int> visited(n,false);
        int res = 0;
        for (int i=0; i<n; i++)
        {
            if (visited[i]) continue;
            int nodeCtr=0, edgeCtr=0;
            visited[i] = true;
            Q.push(i);
            nodeCtr++;
            while(!Q.empty())
            {
                for (int j=Q.size(); j>0; j--)
                {
                    int cur = Q.front();
                    Q.pop();
                    edgeCtr += G[cur].size();
                    for (int nbd: G[cur]) if (!visited[nbd])
                    {
                        visited[nbd] = true;
                        Q.push(nbd);
                        nodeCtr++;
                    }
                }
            }
            // cout<<nodeCtr<<','<<edgeCtr<<endl;
            if (edgeCtr/2==(nodeCtr-1)*nodeCtr/2) res++;
        }
        return res;
    }
};