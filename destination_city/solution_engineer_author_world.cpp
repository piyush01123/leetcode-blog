class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_set<string> nodes;
        for(auto &path: paths) nodes.insert(path[0]);
        for(auto &path: paths) if(!nodes.count(path[1])) return path[1];
        return ""; 
    }
};