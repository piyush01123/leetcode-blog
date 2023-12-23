class Solution {
    int dfs(int i, int j, int[][] grid, int[][] A, int m, int n)
    {
        if (A[i][j]!=-1) return A[i][j];
        if (j==n-1) return A[i][j]=0;
        int res=0;
        for (int ii=Math.max(i-1,0); ii<=Math.min(i+1,m-1); ii++)
            if (grid[ii][j+1]>grid[i][j] && A[ii][j+1]==-1)
                res = Math.max(res, 1+dfs(ii,j+1,grid,A,m,n));
        return A[i][j] = res;
    }
    public int maxMoves(int[][] grid) {
        int m=grid.length, n=grid[0].length, res=0;
        int[][] A = new int[m][n];
        for(int i=0; i<m; i++) Arrays.fill(A[i], -1);
        for(int i=0; i<m; i++)
        {
            res = Math.max(res, dfs(i,0,grid,A,m,n));
            if (res==n-1) return res;
        }
        return res;
    }
}