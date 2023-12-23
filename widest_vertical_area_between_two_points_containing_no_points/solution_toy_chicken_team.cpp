class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        int n = points.size();
        sort(points.begin(),points.end());        
        int res = -1;
        for(int i=1; i<n; i++) res = max(res, points[i][0]-points[i-1][0]);
        return res;
    }
};