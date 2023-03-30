class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size(), maxFirst=values[0]+0, res=INT_MIN;
        for (int i=1; i<n; i++)
        {
            res = max(res, maxFirst+values[i]-i);
            maxFirst = max(maxFirst, values[i]+i);
        }
        return res;
    }
};