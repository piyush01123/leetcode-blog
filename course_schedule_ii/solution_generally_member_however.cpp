class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> G = vector(n,vector<int>{});
        vector<int> inDegrees(n,0);
        for (auto vec: prerequisites)
        {
            int u=vec[1], v=vec[0];
            G[u].push_back(v);
            inDegrees[v]++;
        }
        stack<int> stk;
        vector<int> seq;
        for (int i=0; i<n; i++)
            if (inDegrees[i]==0)
                stk.push(i);
        while (!stk.empty())
        {
            int u = stk.top();
            stk.pop();
            seq.push_back(u);
            for (int v: G[u])
            {
                inDegrees[v]--;
                if (inDegrees[v]==0)
                    stk.push(v);
            }
        }
        if (seq.size() < n) return {};
        return seq;
    }
};