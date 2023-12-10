class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) 
    {
        int n = grid.length;
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        int[][] dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        Queue<Pair<Integer,Integer>> Q = new LinkedList<>();
        Q.add(new Pair<Integer,Integer>(0,0));
        int ctr = 1;
        while (!Q.isEmpty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                Pair<Integer,Integer> rowCol = Q.poll();
                int row=rowCol.getKey(), col=rowCol.getValue();
                if (row==n-1 && col==n-1) return ctr;
                for (int[] dir: dirs)
                {
                    int nbdRow=row+dir[0], nbdCol=col+dir[1];                    
                    if (nbdRow>=0 && nbdRow<n && nbdCol>=0 && nbdCol<n && grid[nbdRow][nbdCol]==0) 
                    {
                        Q.add(new Pair<Integer,Integer>(nbdRow, nbdCol));
                        grid[nbdRow][nbdCol] = 1;
                    }
                }
            }
            ctr++;
        }
        return -1;
    }
}