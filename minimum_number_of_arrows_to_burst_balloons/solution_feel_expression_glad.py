class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        curr, res = points[0][1], 1
        for pt in points:
            if pt[0]>curr:
                curr = pt[1]
                res += 1
        return res