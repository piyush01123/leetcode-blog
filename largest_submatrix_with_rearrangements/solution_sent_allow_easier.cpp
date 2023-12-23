class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m,0));
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(matrix[i][j])   
        if(i==0) heights[i][j] = 1; else heights[i][j] = 1 + heights[i-1][j];
        int res = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> histogram = heights[i];
            sort(histogram.rbegin(),histogram.rend());
            if (histogram[0]==0) continue;
            for(int j=0; j<m; j++) res = max(res, histogram[j]*(j+1));
        }
        return res;
    }
};