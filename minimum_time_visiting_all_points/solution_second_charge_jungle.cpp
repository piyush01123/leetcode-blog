class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int res=0, n=points.size();
        for (int i=1; i<n; i++)
        {
            int x1=points[i-1][0], y1=points[i-1][1], x2=points[i][0], y2=points[i][1];
            int dx = abs(x2-x1), dy = abs(y2-y1);
            res += max(dx,dy);
        }
        return res;       
    }
};