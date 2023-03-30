class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size(), res = 0;
        if (n<3) return n;
        for (int i=0; i<n; i++)
        {
            int x1=points[i][0], y1=points[i][1];
            unordered_map<double,int> ctr;
            for (int j=0; j<n; j++)
            {
                if (i==j) continue;
                int x2=points[j][0], y2=points[j][1];
                double theta = atan2(y2-y1, x2-x1);
                ctr[theta] ++;
            }
            for (auto [k,v]: ctr) res = max(res, v+1);
        }
        return res;
    }
};