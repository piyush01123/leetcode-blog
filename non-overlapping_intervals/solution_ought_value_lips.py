class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda k: k[1])
        n, res, curr = len(intervals), 1, intervals[0][1]
        for i in range(1,n):
            if intervals[i][0]>=curr:
                res += 1
                curr = intervals[i][1]
        return n-res;