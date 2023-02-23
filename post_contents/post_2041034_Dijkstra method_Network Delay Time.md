**Dijsktra"s Algorithm**: Maintain visited nodes in an array Q. Also maintain the distances from source in an array `dist`. Initially `Q = {source}` and `dist={INT_MAX,INT_MAX,INT_MAX...}`  and `dist[source]=0]`. Then while Q is not empty you do the following
- Find which node in Q has the minimum value in `dist` array. Call it `u`.
- For all nodes adjacent to `u`, check if `dist` value can be updated for them. If you update `dist` for any node `v`, then also add `v` to `Q`.

The standard implementation uses a min-heap.
```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph (n);
        for (auto item: times)
        {
            int u=item[0]-1, v=item[1]-1, w=item[2];
            graph[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
        Q.push({0, k-1});
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        while (!Q.empty())
        {
            auto top = Q.top();
            Q.pop();
            int u=top.second, d=top.first;
            for (auto edge: graph[u])
            {
                int v=edge.first, w=edge.second;
                if (d+w < dist[v])
                {
                    dist[v] = d+w;
                    Q.push({d+w, v});
                }
            }
        }
        int res = *max_element(dist.begin(), dist.end());
        return (res==INT_MAX)?-1:res;
    }
};
```
If you dont know about heap, the same logic can be implemented without heap as well with some additional cost but still gets an AC.
```
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
```