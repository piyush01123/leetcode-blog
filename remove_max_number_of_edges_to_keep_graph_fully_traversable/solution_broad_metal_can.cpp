class UnionFind
{
    vector<int> roots;
    vector<int> ranks;
public:
    UnionFind(int sz): roots(sz), ranks(sz)
    {
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=0;}
    }
    int unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return 0;
        if (ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        if (ranks[rootX]< ranks[rootY]) swap(rootX,rootY);
        roots[rootY] = rootX;
        return 1;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        int a=0, b=0, c=0, m=edges.size();
        UnionFind ufAlice=UnionFind(n);
        for (auto &edge: edges) if (edge[0]==3)
        {
            int u=edge[1]-1, v=edge[2]-1;
            c += ufAlice.unionSet(u,v);
        }
        if (c==n-1) return m-c;
        UnionFind ufBob = ufAlice;
        a=c; b=c;
        for (auto &edge: edges) if(edge[0]==1)
        {
            int u=edge[1]-1, v=edge[2]-1;
            a += ufAlice.unionSet(u,v);
        }
        if (a!=n-1) return -1;
        for (auto &edge: edges) if(edge[0]==2)
        {
            int u=edge[1]-1, v=edge[2]-1;
            b += ufBob.unionSet(u,v);
        }
        if (b!=n-1) return -1;
        return m-a-b+c;
    }
};