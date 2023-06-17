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
    public boolean isConnected(int x, int y)
    {
        return (find(x)==find(y));
    }
}


class Solution {
    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) 
    {
        Arrays.sort(edgeList, (veca,vecb)->veca[2]-vecb[2]);
        for (int i=0; i<queries.length; i++)
        {
            int[] row = queries[i]; queries[i] = new int[4];
            for(int j=0;j<3;j++)queries[i][j]=row[j];queries[i][3]=i;
        }
        Arrays.sort(queries, (veca,vecb)->veca[2]-vecb[2]);

        UnionFind uf = new UnionFind(n);
        boolean[] res = new boolean[queries.length];
        int edgeIdx = 0;
        for (int[] query: queries)
        {
            int p=query[0], q=query[1], limit=query[2], qIdx=query[3];
            while (edgeIdx<edgeList.length) 
            {
                int u=edgeList[edgeIdx][0], v=edgeList[edgeIdx][1], dis=edgeList[edgeIdx][2];
                if (dis>=limit) break;
                uf.unionSet(u, v);
                edgeIdx++;
            }
            res[qIdx] = uf.isConnected(p,q);
        }
        return res;
    }
}