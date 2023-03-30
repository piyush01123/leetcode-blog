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