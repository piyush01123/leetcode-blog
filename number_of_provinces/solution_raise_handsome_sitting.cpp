class UF
{
    vector<int> roots, ranks;
public:
    UF(int n)
    {
        roots.resize(n);
        ranks.resize(n,1);
        for(int i=0; i<n; i++) roots[i] = i;
    }
    int find(int u)
    {
        if(roots[u]==u) return u;
        return roots[u] = find(roots[u]);
    }
    void unionSet(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u==v) return;
        if (ranks[u]==ranks[v]) ranks[u]++;
        if (ranks[u]<ranks[v]) swap(u,v);
        roots[v] = u;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        UF uf(n);
        unordered_set<int> roots;
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++)
            if(isConnected[i][j]) uf.unionSet(i,j);
        for(int i=0; i<n; i++) roots.insert(uf.find(i));
        return roots.size();
    }
};