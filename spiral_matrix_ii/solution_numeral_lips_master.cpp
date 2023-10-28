class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> M(n, vector<int>(n,0));
        int i=0, j=0, di=0, dj=1;
        for (int cur=1; cur<=n*n; cur++)
        {
            M[i][j] = cur;
            if (i+di<0 || i+di>=n || j+dj<0 || j+dj>=n || M[i+di][j+dj]>0)
            {
                int temp = di;
                di = dj;
                dj = -temp;
            }
            i += di;
            j += dj;
        }
        return M;
    }
};