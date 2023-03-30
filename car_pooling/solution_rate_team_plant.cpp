class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,vector<int>> fromMap, toMap;
        for (int i=0; i<trips.size(); i++)
        {
            vector<int> trip = trips[i];
            fromMap[trip[1]].push_back(i);        
            toMap[trip[2]].push_back(i);        
        }
        int curr=0;
        for (int point=0; point<=1000; point++)
        {
            if (fromMap.find(point)!=fromMap.end())
                for (int index: fromMap[point]) curr+=trips[index][0];
            if (toMap.find(point)!=toMap.end())
                for (int index: toMap[point]) curr-=trips[index][0];
            if (curr>capacity) return false;
        }
        return true;
    }
};