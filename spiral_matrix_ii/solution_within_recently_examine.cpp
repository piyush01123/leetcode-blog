class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> M(n, vector<int>(n,0));
        int i=0, j=0, di=0, dj=1;
        for (int cur=1; cur<=n*n; cur++)
        {
            M[i][j] = cur;
            i += di;
            j += dj;
            if (i<0 || i>=n || j<0 || j>=n || M[i][j]>0)
            {
                i -= di;
                j -= dj;
                int temp = di;
                di = dj;
                dj = -temp;
                i += di;
                j += dj;
            }
        }
        return M;
    }
};