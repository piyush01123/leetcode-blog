class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001, 0);
        for (vector<int> trip: trips)
        {
            passengers[trip[1]]+=trip[0];
            passengers[trip[2]]-=trip[0];
        }
        if (passengers[0]>capacity) return false;
        for (int i=1; i<passengers.size(); i++)
        {
            passengers[i]+=passengers[i-1];
            if (passengers[i]>capacity) return false;
        }
        return true;
    }
};