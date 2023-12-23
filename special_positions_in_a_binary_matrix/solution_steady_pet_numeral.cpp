class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size(), count = 0;
        vector<int> rowSums(m,0), colSums(n,0);
        for(int i=0; i<m; i++) for (int j=0; j<n; j++)
        {
            rowSums[i] += mat[i][j];
            colSums[j] += mat[i][j];
        }
        for(int i=0; i<m; i++) for (int j=0; j<n; j++)
            if(mat[i][j]==1 && rowSums[i]==1 && colSums[j]==1) count++;
        return count;
    }
};