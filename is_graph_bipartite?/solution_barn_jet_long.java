class Solution {
    public boolean isBipartite(int[][] graph) 
    {
        int n=graph.length, uncolored=0, white=1, black=-1;
        int[] colors = new int[n];
        Arrays.fill(colors, uncolored);
        Queue<Integer> Q = new LinkedList<Integer>();
        for (int i=0; i<n; i++) if (colors[i]==uncolored)
        {
            colors[i] = white;
            Q.add(i);
            while (!Q.isEmpty())
            {
                for (int j=Q.size(); j>0; j--)
                {
                    int cur = Q.poll();
                    for (int nbd: graph[cur])
                    {
                        if (colors[nbd]==colors[cur]) return false;
                        else if (colors[nbd]==uncolored)
                        {
                            colors[nbd] = -colors[cur];
                            Q.add(nbd);
                        }
                    }
                }
            }
        }
        return true;
    }
}