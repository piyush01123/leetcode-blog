class UnionFind
{
    vector<int>roots;
    vector<int>ranks;
public:
    UnionFind(int sz): roots(sz), ranks(sz)
    {
        for(int i=0; i<sz; i++)
        {
            roots[i] = i;
            ranks[i] = 1;
        }
    }
    void Union(int u, int v)
    {
        u = Find(u);
        v = Find(v);
        if (u==v) return;
        if (ranks[u]==ranks[v]) ranks[u]++;
        else if (ranks[u]<ranks[v]) swap(u,v);
        roots[u] = v;
    }
    int Find(int u)
    {
        if (roots[u]==u) return u;
        return roots[u] = Find(roots[u]);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++)
        if (isConnected[i][j]) uf.Union(i,j);
        unordered_set<int> roots;
        for (int i=0; i<n; i++) roots.insert(uf.Find(i));
        return roots.size();
    }
};