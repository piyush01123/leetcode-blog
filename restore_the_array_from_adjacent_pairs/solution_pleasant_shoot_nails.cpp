class Solution {
    vector<int>res;
public:
    void dfs(unordered_map<int,vector<int>> &G, int cur, int par)
    {
        res.push_back(cur);
        for (int ch: G[cur])if(ch!=par) dfs(G,ch,cur);
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int,vector<int>> G;
        for(auto &v: adjacentPairs)
        {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        int cur;
        for(auto &[k,v]:G)if(v.size()==1) {cur=k;break;}
        dfs(G,cur,-1);
        return res;
    }
};