class UnionFind
{
    int[] roots;
    int[] ranks;
    public UnionFind(int sz)
    {
        roots = new int[sz];
        ranks = new int[sz];
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=0;}
    }
    public int unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return 0;
        if(ranks[rootX]==ranks[rootY])ranks[rootX]++;
        if (ranks[rootX]<ranks[rootY])
            {int temp=rootX; rootX=rootY; rootY=temp;}
        roots[rootY] = rootX;
        return 1;
    }
    public int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    public UnionFind(UnionFind other)
    {
        roots = other.roots.clone();
        ranks = other.ranks.clone();
    }
};


class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) 
    {
        int a=0, b=0, c=0, m=edges.length;
        UnionFind ufAlice = new UnionFind(n);
        for (int[] edge: edges) if (edge[0]==3)
        {
            int u=edge[1]-1, v=edge[2]-1;
            c += ufAlice.unionSet(u,v);
        }
        if (c==n-1) return m-c;
        UnionFind ufBob = new UnionFind(ufAlice);
        a=c; b=c;
        for (int[] edge: edges) if(edge[0]==1)
        {
            int u=edge[1]-1, v=edge[2]-1;
            a += ufAlice.unionSet(u,v);
        }
        if (a!=n-1) return -1;
        for (int[] edge: edges) if(edge[0]==2)
        {
            int u=edge[1]-1, v=edge[2]-1;
            b += ufBob.unionSet(u,v);
        }
        if (b!=n-1) return -1;
        return m-a-b+c;
    }
};