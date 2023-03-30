class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> zeroRows, zeroCols;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (matrix[i][j]==0)
                {
                    zeroRows.push_back(i);
                    zeroCols.push_back(j);
                }
            }
        }
        for (int i: zeroRows)
            for (int j=0; j<n; ++j)
                matrix[i][j] = 0;
        for (int j: zeroCols)
            for (int i=0; i<m; ++i)
                matrix[i][j] = 0;
    }
};