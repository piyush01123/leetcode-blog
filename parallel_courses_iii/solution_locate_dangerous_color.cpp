class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<vector<int>> G(n);
        vector<int> inDegree(n,0);
        for(auto &r: relations) 
        {
            int u=r[0]-1, v=r[1]-1;
            G[u].push_back(v);
            inDegree[v]++;
        }
        queue<int>Q;
        vector<int> minTime(n,0);
        for(int i=0;i<n;i++) if(!inDegree[i]) {Q.push(i); minTime[i]=time[i];}
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (int v: G[u])
            {
                minTime[v] = max(minTime[v], minTime[u]+time[v]);
                inDegree[v]--;
                if (!inDegree[v]) Q.push(v);
            }
        }
        return *max_element(minTime.begin(),minTime.end());
    }
};