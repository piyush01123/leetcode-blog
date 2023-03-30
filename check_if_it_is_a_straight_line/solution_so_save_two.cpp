class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float x1=coordinates[0][0], y1=coordinates[0][1];
        float x2=coordinates[1][0], y2=coordinates[1][1];
        // float m = (y2-y1)/(x2-x1);
        // float c = y1 - m*x1;
        // cout << m << ' ' << c << endl;
        // for (auto coord: coordinates)
        // {
        //     float x=coord[0], y=coord[1];
        //     if (m*x + c != y) return false;
        // }
        // return true;
        for (auto coord: coordinates)
        {
            float x3=coord[0], y3=coord[1];
            float test = x1 * (y2 - y3) - y1 * (x2 - x3) + 1 * (x2*y3 - x3*y2);
            if (test != 0) return false;
        }
        return true;
    }
};