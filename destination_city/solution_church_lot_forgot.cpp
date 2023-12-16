class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string,string> G;
        for(auto &path: paths) G[path[0]] = path[1];
        string cur = paths[0][0];
        while(G.count(cur)) cur = G[cur];
        return cur;        
    }
};