class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        unordered_set<int> res;
        for(int i=0; i<n; i++) res.insert(i);
        for(auto &edge: edges) if (res.count(edge[1])) res.erase(edge[1]);
        return vector<int>(res.begin(),res.end());
    }
};