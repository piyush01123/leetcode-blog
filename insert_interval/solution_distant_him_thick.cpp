class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int start=newInterval[0], end=newInterval[1], n=intervals.size();
        if (n==0) return {newInterval};
        vector<int> starts(n), ends(n);
        for(int i=0; i<n; i++)
        {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        int delStart = lower_bound(ends.begin(), ends.end(), start) - ends.begin();
        int delEnd = upper_bound(starts.begin(), starts.end(), end) - starts.begin();
        if (delEnd>0 && delStart<n)
        {
            int prevStart = intervals[delStart][0], prevEnd = intervals[delEnd-1][1];
            newInterval[0] = min(start, prevStart);
            newInterval[1] = max(end, prevEnd);
            for (int i=delStart; i<delEnd; i++) intervals.erase(intervals.begin()+delStart);
        }
        intervals.insert(intervals.begin()+delStart, newInterval);
        return intervals;
    }
};