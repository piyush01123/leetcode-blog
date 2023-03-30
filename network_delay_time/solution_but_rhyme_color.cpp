void pv(vector<int>v){for(int k:v)cout<<k<<',';cout<<endl;}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto edge: times)
        {
            int u=edge[0]-1, v=edge[1]-1, w=edge[2];
            graph[u].push_back({v,w});
        }
        vector<int> Q {k-1};
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        while (Q.size()>0)
        {
            int u, minStart=INT_MAX;
            for (int node: Q)
            {
                if (dist[node]<minStart)
                {
                    minStart=dist[node];
                    u = node;
                }
            }
            // u has the min distance out of all nodes in Q
            Q.erase(find(Q.begin(),Q.end(),u));
            for (auto edge: graph[u])
            {
                int v=edge.first, w=edge.second;
                if (dist[u]+w < dist[v])
                {
                    dist[v] = dist[u]+w;
                    Q.push_back(v);
                }
            }
        }
        int res = *max_element(dist.begin(),dist.end());
        return (res==INT_MAX)?-1:res;
    }
};