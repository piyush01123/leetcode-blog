# Intuition
This is a straightforward graph traversal problem.
# Approach
We can do a simple BFS or DFS traversal to solve this.
# Complexity
- Time complexity:
O(V) where V is the number of rooms
- Space complexity:
O(V) where V is the number of rooms
# Code
## BFS solution
```
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited = vector<bool>(n,false);
        queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                int cur = Q.front();
                Q.pop();
                visited[cur] = true;
                for (int adj: rooms[cur]) if (!visited[adj]) Q.push(adj);
            }
        }
        for (bool v: visited) if (!v) return false;
        return true;
    }
};
```
## DFS solution
```
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
```