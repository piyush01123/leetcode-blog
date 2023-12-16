class Solution {
public:
    int maxRectHistogram(vector<int>&heights, int n)
    {
        vector<int> lefts(n), rights(n);
        lefts[0]=-1; rights[n-1]=n;
        for (int i=1; i<n; i++)
        {
            int p = i-1;
            while(p>=0 && heights[p]>=heights[i]) p = lefts[p];
            lefts[i] = p;
        }
        for (int i=n-2; i>=0; i--)
        {
            int p = i+1;
            while(p<n && heights[p]>=heights[i]) p = rights[p];
            rights[i] = p;
        }
        int res=0;
        for (int i=0; i<n; i++) res = max(res, (rights[i]-lefts[i]-1)*heights[i]);
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int H = matrix.size(), W = matrix[0].size(), res=0;
        vector<vector<int>> heights(H, vector<int>(W,0));
        for(int i=0; i<H; i++) for(int j=0; j<W; j++) if(matrix[i][j]=='1')
        if (i==0) heights[i][j] = 1; else heights[i][j] = heights[i-1][j]+1;
        for (int i=0; i<H; i++) res = max(res, maxRectHistogram(heights[i], W));
        return res;
    }
};