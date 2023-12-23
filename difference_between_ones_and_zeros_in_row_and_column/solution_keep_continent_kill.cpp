class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowSums(m,0), colSums(n,0);
        for(int i=0; i<m; i++) for(int j=0; j<n; j++)
        {
            if (grid[i][j])
            {
                rowSums[i]++;
                colSums[j]++;
            }
        }
        vector<vector<int>>res(m, vector<int>(n,0));
        for(int i=0; i<m; i++) for(int j=0; j<n; j++)
            res[i][j] = 2 * (rowSums[i] + colSums[j]) - m - n;
        return res;
    }
};