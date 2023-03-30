class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxFirst = values[0], res=INT_MIN;
        for (int i=1; i<values.size(); i++)
        {
            res = max(res, maxFirst+values[i]-i);
            maxFirst = max(maxFirst, values[i]+i);
        }
        return res;
    }
};