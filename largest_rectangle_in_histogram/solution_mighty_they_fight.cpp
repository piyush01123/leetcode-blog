class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int> lefts(n), rights(n);
        lefts[0]=-1; rights[n-1]=n;
        for(int i=1; i<n; i++)
        {
            int p = i-1;
            while (p>=0 && heights[p]>=heights[i]) p = lefts[p];
            lefts[i] = p;
        }
        for(int i=n-2; i>=0; i--)
        {
            int p = i+1;
            while (p<n && heights[p]>=heights[i]) p = rights[p];
            rights[i] = p;
        }
        int res = 0;
        for (int i=0; i<n; i++) res = max(res, heights[i]*(rights[i]-lefts[i]-1));
        return res;
    }
};