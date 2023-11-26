class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<bool> hasIncomingEdges(n, false);
        for(auto &edge: edges) hasIncomingEdges[edge[1]]=true;
        vector<int> res;
        for(int i=0; i<n; i++) if (!hasIncomingEdges[i]) res.push_back(i);
        return res;
    }
};