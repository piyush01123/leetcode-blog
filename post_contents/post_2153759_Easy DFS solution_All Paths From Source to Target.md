```
class Solution {
public:
    void dfs(vector<vector<int>> graph, int u, int n, vector<int>&path,
            vector<vector<int>> &paths)
    {
        path.push_back(u);
        if (u==n-1) paths.push_back(path);
        for (int v: graph[u]) dfs(graph,v,n,path,paths);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>path;
        vector<vector<int>> paths;
        dfs(graph,0,n,path,paths);
        return paths;
    }
};
```