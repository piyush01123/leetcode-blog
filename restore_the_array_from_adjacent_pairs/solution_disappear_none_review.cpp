class Solution {
    vector<int>res;
public:
    void dfs(unordered_map<int,vector<int>> &H, int cur, int par)
    {
        res.push_back(cur);
        for (int ch: H[cur])if(ch!=par) dfs(H,ch,cur);
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int,vector<int>> H;
        for(auto &v: adjacentPairs)
        {
            H[v[0]].push_back(v[1]);
            H[v[1]].push_back(v[0]);
        }
        int cur;
        for(auto &[k,v]:H)if(v.size()==1) {cur=k;break;}
        dfs(H,cur,-1);
        return res;
    }
};