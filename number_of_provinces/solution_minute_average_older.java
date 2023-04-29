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
    public void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return;
        if (ranks[rootX]<ranks[rootY]){int temp=rootX;rootX=rootY;rootY=temp;}
        roots[rootY] = rootX;
    }
    public int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    public int numGroups(int sz)
    {
        HashSet<Integer> mySet = new HashSet<Integer>();
        for (int i=0; i<sz; i++) mySet.add(find(i));
        return mySet.size();
    }
}


class Solution 
{
    public int findCircleNum(int[][] isConnected) 
    {
        int n=isConnected.length;
        UnionFind uf = new UnionFind(n);
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(isConnected[i][j]==1)
            uf.unionSet(i,j);
        return uf.numGroups(n);
    }
}