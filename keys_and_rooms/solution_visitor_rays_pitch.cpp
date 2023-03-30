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