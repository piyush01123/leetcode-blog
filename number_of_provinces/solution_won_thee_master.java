public class UnionFind
{
    int[] roots, ranks;
    UnionFind(int sz)
    {
        roots = new int[sz]; ranks = new int[sz];
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=0;}
    }
    void unionSet(int x, int y)
    {
        x = find(x); y=find(y);
        if (x==y) return;
        if (ranks[x]==ranks[y])ranks[x]++;
        if (ranks[x] <ranks[y]){int t=x; x=y; y=t;}
        roots[y]=x;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
}

class Solution {
    public int findCircleNum(int[][] isConnected) 
    {
        int n=isConnected.length;
        UnionFind uf = new UnionFind(n);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(isConnected[i][j]==1) uf.unionSet(i,j);
        HashSet<Integer> roots = new HashSet<Integer>();
        for(int i=0; i<n; i++)roots.add(uf.find(i));
        return roots.size();
    }
}