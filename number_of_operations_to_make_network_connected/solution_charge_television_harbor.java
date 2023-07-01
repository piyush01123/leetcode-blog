class UnionFind
{
    int[] roots;
    int[] ranks;
    UnionFind(int sz)
    {
        roots = new int[sz];
        ranks = new int[sz];
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=0;}
    }
    int unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return 0;
        if (ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        if (ranks[rootX] <ranks[rootY])
            {int temp=rootX;rootX=rootY;rootY=temp;}
        roots[rootY] = rootX;
        return 1;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    int numGroups(int sz)
    {
        HashSet<Integer> mySet = new HashSet<Integer>();
        for (int i=0; i<sz; i++) mySet.add(find(i));
        return mySet.size();
    }
}

class Solution {
    public int makeConnected(int n, int[][] connections)
    {
        int ctr = 0;
        UnionFind uf = new UnionFind(n);
        for (int[] edge: connections) ctr+=uf.unionSet(edge[0],edge[1]);
        int extraCables = connections.length-ctr;
        int ng = uf.numGroups(n);
        if (extraCables<ng-1) return -1;
        return ng-1;
    }
}