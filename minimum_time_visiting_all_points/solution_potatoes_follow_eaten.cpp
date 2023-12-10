class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int res=0, n=points.size();
        for (int i=1; i<n; i++)
        {
            vector<int> p1 = points[i],  p2 = points[i-1];
            int dx = abs(p2[0]-p1[0]), dy = abs(p2[1]-p1[1]);
            res += max(dx,dy);
        }
        return res;       
    }
};