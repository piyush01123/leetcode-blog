class UF
{
    public:
    vector<int> grouping;
    vector<int> ranking;
    UF(int n)
    {
        grouping = vector<int>(n,0);
        ranking = vector<int>(n, 0);
        for (int i=0; i<n; i++) grouping[i]=i;
    }
    int find(int u)
    {
        if (grouping[u]!=u) grouping[u]=find(grouping[u]);
        return grouping[u];
    }
    bool join(int u, int v)
    {
        int grp_u=find(u), grp_v=find(v);
        if (grp_u==grp_v) return false;
        if (ranking[u]>ranking[v]) grouping[grp_v]=grp_u;
        else if (ranking[v]<ranking[u]) grouping[grp_u]=grp_v;
        else 
        {
            grouping[grp_u]=grp_v;
            ranking[grp_v]++;
        }
        return true;
    }
    
};
int abs(int a)
{
    return (a<0)?-a:a;
}
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        vector<pair<int, pair<int,int>>> graph;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int xi=points[i][0], yi=points[i][1];
                int xj=points[j][0], yj=points[j][1];
                int d = abs(xi-xj) + abs(yi-yj);
                graph.push_back({d, {i,j}});
            }
        }
        sort(graph.begin(), graph.end());
        // for (auto p: graph) cout<<p.first<<'('<<p.second.first<<','<<p.second.second<<')'<<endl;
        UF uf(n);
        int cost=0;
        int edges_used=0;
        for (int i=0; i<graph.size(); i++)
        {
            if (edges_used==n-1) break;
            int u=graph[i].second.first, v=graph[i].second.second, w=graph[i].first;
            if (uf.join(u,v))
            {
                cost+=w;
                edges_used++;
            }
        }
        return cost;
    }
};