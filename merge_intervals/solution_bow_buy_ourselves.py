# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals: 'List[Interval]') -> 'List[Interval]':
        if len(intervals)==0:
            return intervals
        intervals = sorted(intervals, key=lambda x: x.start)
        merged = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i].start<=merged[-1].end:
                last_interval = merged.pop()
                merged.append(Interval(last_interval.start, max(last_interval.end, intervals[i].end)))
            else:
                merged.append(intervals[i])
        return merged
        