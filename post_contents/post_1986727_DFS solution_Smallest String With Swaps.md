- Create graph using `pairs` as adjancency list.
- Start with a node. Do DFS traversal. Sort the node ids (string indices) and characters both. Then put the characters in order.
- Repeat for all nodes. Do not do for already visited nodes.

```
class Solution {
public:
    int n;
    vector<vector<int>> edges;
    vector<bool> visited;
    
    void DFS(int src, vector<int>&visited_nodes)
    {
        visited[src]=true;
        visited_nodes.push_back(src);
        for (int dest: edges[src])
            if (!visited[dest]) DFS(dest, visited_nodes);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        n = s.size();
        edges =  vector<vector<int>>(n, vector<int>{});
        for (auto p: pairs)
        {
            int u=p[0], v=p[1];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        visited = vector<bool>(n, false);
        for (int u=0; u<n; u++)
        {
            if (!visited[u])
            {
                vector<int> visited_nodes;
                DFS(u, visited_nodes);
                vector<char> visited_chars;
                for (int i: visited_nodes) visited_chars.push_back(s[i]);
                sort(visited_chars.begin(), visited_chars.end());
                sort(visited_nodes.begin(), visited_nodes.end());
                for (int i=0; i<visited_nodes.size(); i++)
                    s[visited_nodes[i]]=visited_chars[i];
            }
        }
        return s;
    }
};
```