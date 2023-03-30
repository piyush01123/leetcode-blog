class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<bool>&visited, int u)
    {
        visited[u] = true;
        for (int v: rooms[u]) if (!visited[v]) dfs(rooms,visited,v);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited = vector<bool>(n,false);
        dfs(rooms, visited, 0);
        for (bool v: visited) if (!v) return false;
        return true;
    }
};