class Solution {
    boolean dfs(int[][] G, int[] colors, int cur)
    {
        boolean res=true;
        for (int nbd: G[cur])
        {
            if (colors[nbd]==colors[cur]) return false;
            else if (colors[nbd]==0)
            {
                colors[nbd] = -colors[cur];
                res &= dfs(G, colors, nbd);
            }
        }
        return res;
    }
    public boolean isBipartite(int[][] graph) 
    {
        int n = graph.length, uncolored=0, white=1, black=-1;
        int[] colors = new int[n];
        Arrays.fill(colors, uncolored);
        for (int i=0; i<n; i++) if (colors[i]==uncolored)
        {
            colors[i] = white;
            boolean res = dfs(graph, colors, i);
            if (!res) return false;
        }
        return true;
    }
}