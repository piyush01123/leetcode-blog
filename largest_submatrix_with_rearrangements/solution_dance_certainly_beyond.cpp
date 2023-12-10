class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m,0));
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) 
          if(matrix[i][j]) heights[i][j] = (i==0) ? 1 : 1 + heights[i-1][j];
        int res = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> histogram = heights[i];
            sort(histogram.rbegin(),histogram.rend());
            for(int j=0; j<m && histogram[j]; j++) res = max(res, histogram[j]*(j+1));
        }
        return res;
    }
};