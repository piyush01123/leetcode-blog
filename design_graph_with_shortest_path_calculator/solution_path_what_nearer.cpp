#define pii pair<int,int>
class Graph 
{
    vector<vector<pii>> G;
public:
    Graph(int n, vector<vector<int>>& edges) 
    {
        G.resize(n);
        for (auto &edge: edges)
        {
            int u=edge[0], v=edge[1], w=edge[2];
            G[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        int u=edge[0], v=edge[1], w=edge[2];
        G[u].push_back({v,w});        
    }
    
    int shortestPath(int node1, int node2) 
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(G.size(),INT_MAX);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty())
        {
            pii ud = pq.top(); pq.pop();
            int d=ud.first, u=ud.second;
            for(auto vw: G[u])
            {
                int v = vw.first, w=vw.second;
                if (d+w<dist[v])
                {
                    dist[v] = d+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */