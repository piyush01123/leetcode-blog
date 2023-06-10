class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        if (n==1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (auto &interval: intervals)
        {
            if (interval[0]<=res.back()[1])
            {
                vector<int> lastInterval = res.back();
                res.pop_back();
                res.push_back({lastInterval[0], max(interval[1], lastInterval[1])});
            } else 
                res.push_back(interval);
        }        
        return res;
    }
};