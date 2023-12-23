class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        unordered_map<int,vector<int>> reachable_routes;
        for (int i=0; i<routes.size(); i++)
            for (int node: routes[i]) reachable_routes[node].push_back(i);
        queue<int> Q;
        Q.push(source);
        int ctr = 0;
        unordered_set<int> visited;
        vector<bool> traversed_routes(routes.size(), false);
        while(!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                int cur = Q.front();
                Q.pop();
                visited.insert(cur);
                if (cur==target) return ctr;
                for (int route_id: reachable_routes[cur])
                    if (traversed_routes[route_id]) continue;
                    else
                    {
                        traversed_routes[route_id] = true;                        
                        for (int nbd: routes[route_id])
                            if(!visited.count(nbd)) Q.push(nbd);
                    }
            }
            ctr++;
        }
        return -1;
    }
};