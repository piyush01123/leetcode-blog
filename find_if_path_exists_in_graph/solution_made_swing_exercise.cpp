class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source==destination) return true;
        queue<int> Q;
        Q.push(source);
        vector<vector<int>> adjL(n, vector<int>{});
        for (auto v: edges) {adjL[v[0]].push_back(v[1]);
                             adjL[v[1]].push_back(v[0]);
                            }
        vector<bool> visited(n, false);
        visited[source]=true;
        while (Q.size()>0)
        {
            int v = Q.front(); 
            visited[v] = true;
            Q.pop();
            for (int node: adjL[v]) if (!visited[node]) Q.push(node);
        }
        return visited[destination];
    }
};