class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> G = vector(n,vector<int>{});
        vector<int> inDegrees(n,0);
        for (auto vec: prerequisites)
        {
            int u=vec[1], v=vec[0];
            G[u].push_back(v);
            inDegrees[v]++;
        }
        queue<int> Q;
        vector<int> seq;
        for (int i=0; i<n; i++)
            if (inDegrees[i]==0)
                Q.push(i);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            seq.push_back(u);
            for (int v: G[u])
            {
                inDegrees[v]--;
                if (inDegrees[v]==0)
                    Q.push(v);
            }
        }
        return seq.size()==n;
    }
};