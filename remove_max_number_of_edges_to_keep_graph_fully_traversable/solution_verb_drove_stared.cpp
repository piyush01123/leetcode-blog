class UnionFind
{
    vector<int> roots;
    vector<int> sizes;
public:
    UnionFind(int sz): roots(sz), sizes(sz)
    {
        for(int i=0; i<sz; i++){roots[i]=i; sizes[i]=1;}
    }
    int unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return 0;
        if (sizes[rootX]<sizes[rootY]) swap(rootX,rootY);
        sizes[rootX] += sizes[rootY];
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
        vector<vector<int>> edgesT1, edgesT2, edgesT3;
        for (auto &edge: edges)
        {
            if (edge[0]==1) edgesT1.push_back(edge);
            if (edge[0]==2) edgesT2.push_back(edge);
            if (edge[0]==3) edgesT3.push_back(edge);
        }
        int a=0, b=0, c=0, m=edges.size();
        UnionFind ufAlice=UnionFind(n);
        for (auto &edge: edgesT3)
        {
            int u=edge[1]-1, v=edge[2]-1;
            c += ufAlice.unionSet(u,v);
        }
        if (c==n-1) return m-c;
        UnionFind ufBob = ufAlice;
        a=c; b=c;
        for (auto &edge: edgesT1)
        {
            int u=edge[1]-1, v=edge[2]-1;
            a += ufAlice.unionSet(u,v);
        }
        for (auto &edge: edgesT2)
        {
            int u=edge[1]-1, v=edge[2]-1;
            b += ufBob.unionSet(u,v);
        }
        if (a!=n-1 || b!=n-1) return -1;
        return m-a-b+c;
    }
};