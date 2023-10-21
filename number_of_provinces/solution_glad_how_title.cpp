class UnionFind
{
    vector<int> roots, ranks;
public:
    UnionFind(int sz):roots(sz),ranks(sz){for(int i=0;i<sz;i++){roots[i]=i;ranks[i]=0;}}
    void unionSet(int x, int y)
    {
        x=find(x); y=find(y);
        if (x==y) return;
        if (ranks[x]==ranks[y]) ranks[x]++;
        if (ranks[x] <ranks[y]) swap(x,y);
        roots[y] = x;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(isConnected[i][j]) uf.unionSet(i,j);
        unordered_set<int>roots;
        for(int i=0; i<n; i++) roots.insert(uf.find(i));
        return roots.size();
    }
};