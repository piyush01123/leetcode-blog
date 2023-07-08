class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<bool>> M(m, vector<bool>(n, false));
        int i=0, j=0, di=0, dj=1;
        vector<int> res;
        for (int k=0; k<m*n; k++)
        {
            res.push_back(matrix[i][j]);
            M[i][j] = true;
            if (i+di<0 || i+di>=m || j+dj<0 || j+dj>=n || M[i+di][j+dj])
            {
                int temp=di;
                di = dj;
                dj = -temp;
            }
            i += di;
            j += dj;
        }
        return res;
    }
};