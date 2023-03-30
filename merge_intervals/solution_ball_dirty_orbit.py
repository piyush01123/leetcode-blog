# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals: 'List[Interval]') -> 'List[Interval]':
        if len(intervals)==0:
            return []
        intervals = [(int.start, int.end) for int in intervals]
        intervals = sorted(intervals, key=lambda x: x[0])
        if intervals is None:
            return intervals
        merged = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i][0]<=merged[-1][1]:
                last_interval = merged.pop()
                merged.append((last_interval[0], max(last_interval[1], intervals[i][1])))
            else:
                merged.append(intervals[i])
        merged = [Interval(m[0], m[1]) for m in merged]
        return merged
        