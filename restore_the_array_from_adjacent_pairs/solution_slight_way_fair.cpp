class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int,vector<int>> G;
        for(auto &v: adjacentPairs)
        {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        int start=-1,end=-1;
        for(auto &[k,v]:G)if(v.size()==1)if(start!=-1){end=k;break;}else start=k;
        int cur=start,prev=-1;
        vector<int> res {start};
        while(cur!=end)
        {
            for (int next: G[cur]) if(next==prev) continue; 
            else {prev=cur; cur=next; break;}
            res.push_back(cur);
        }
        return res;
    }
};