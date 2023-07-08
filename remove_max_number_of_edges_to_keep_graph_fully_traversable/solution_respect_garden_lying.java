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
    boolean isConnected(int x, int y)
    {
        return (find(x)==find(y));
    }
    int numGroups(int sz)
    {
        HashSet<Integer> mySet = new HashSet<Integer>();
        for(int i=0; i<sz; i++) mySet.add(find(i));
        return mySet.size();
    }
};

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) 
    {
        List<int[]> edgesT1 = new ArrayList<int[]>();
        List<int[]> edgesT2 = new ArrayList<int[]>();
        List<int[]> edgesT3 = new ArrayList<int[]>();
        for (int[] edge: edges)
        {
            if (edge[0]==1) edgesT1.add(edge);
            if (edge[0]==2) edgesT2.add(edge);
            if (edge[0]==3) edgesT3.add(edge);
        }
        int ctr = 0;
        UnionFind ufAlice = new UnionFind(n), ufBob = new UnionFind(n);
        for (int[] edge: edgesT3)
        {
            int u=edge[1]-1, v=edge[2]-1;
            if (ufAlice.isConnected(u,v) && ufBob.isConnected(u,v)) ctr++;
            else {ufAlice.unionSet(u,v); ufBob.unionSet(u,v);}
        }
        for (int[] edge: edgesT1)
        {
            int u=edge[1]-1, v=edge[2]-1;
            if (ufAlice.isConnected(u,v)) ctr++;
            else ufAlice.unionSet(u,v); 
        }
        for (int[] edge: edgesT2)
        {
            int u=edge[1]-1, v=edge[2]-1;
            if (ufBob.isConnected(u,v)) ctr++;
            else ufBob.unionSet(u,v); 
        }
        if (ufAlice.numGroups(n)!=1 || ufBob.numGroups(n)!=1) return -1;
        return ctr;
    }
}