```
bool mycomp(vector<int>&a, vector<int>&b)
{
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.size()==1) return 0;
        sort(intervals.begin(), intervals.end(), mycomp);
        int n=intervals.size(), curr=intervals[0][1], res=0;
        for (int i=1; i<n; i++)
        {
            if (intervals[i][0]>=curr) curr = intervals[i][1];
            else res ++;
        }
        return res;
    }
};
```

```
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda k: k[1])
        n, res, curr = len(intervals), 0, intervals[0][1]
        for i in range(1,n):
            if intervals[i][0]>=curr:
                curr = intervals[i][1]
			else:
			    res += 1
        return res
```