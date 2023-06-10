class UnionFind
{
    vector<int> roots, ranks, edges;
public:
    UnionFind(int sz): roots(sz),ranks(sz),edges(sz)
    {
        for(int i=0; i<sz; i++)
        {
            roots[i]=i;
            ranks[i]=0;
            edges[i]=0;
        }
    }
    void unionSet(int x, int y)
    {
        int rootX=find(x);
        int rootY=find(y);
        edges[rootX]++;
        if (rootX==rootY) return;
        if (ranks[rootX]==ranks[rootY])ranks[rootX]++;
        if (ranks[rootX] <ranks[rootY]) swap(rootX,rootY);
        roots[rootY] = rootX;
        edges[rootX] += edges[rootY];
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    int getAnswer()
    {
        int res=0;
        unordered_map<int,int>H;
        for(int i=0; i<roots.size(); i++) H[find(i)]++;
        for (auto &[root, numNodes]: H)
        {
            int numEdges = edges[root];
            if (numEdges == numNodes*(numNodes-1)/2) res++;
        }
        return res;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        UnionFind uf = UnionFind(n);
        for(auto &edge: edges)
        {
            int u=edge[0], v=edge[1];
            uf.unionSet(u,v);
        }
        return uf.getAnswer();
    }
};