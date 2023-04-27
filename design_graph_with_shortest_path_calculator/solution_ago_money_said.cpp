#define pi pair<int,int>
class Graph {
    int V;
    vector<vector<pi>> G;
public:
    Graph(int n, vector<vector<int>>& edges) {
        V = n;
        G = vector<vector<pi>>(n);
        for (auto edge: edges) G[edge[0]].push_back({edge[1],edge[2]});
    }
    
    void addEdge(vector<int> edge) 
    {
        G[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) 
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0,node1});
        dist[node1] = 0;
        while(!pq.empty())
        {
            pi node = pq.top();
            pq.pop();
            int u = node.second, d = node.first;
            for (pi nbd: G[u])
            {
                int v = nbd.first, w = nbd.second;
                if (d+w<dist[v])
                {
                    dist[v] = d+w;
                    pq.push({d+w, v});
                }
            }
        }
        return (dist[node2]==INT_MAX)?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */