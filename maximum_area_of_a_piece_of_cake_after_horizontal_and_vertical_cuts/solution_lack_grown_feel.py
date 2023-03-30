class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        M = 1000000007
        horizontalCuts.sort()
        verticalCuts.sort()
        va, vb = [horizontalCuts[0]], [verticalCuts[0]]
        for i in range(1,len(horizontalCuts)):
            va.append(horizontalCuts[i]-horizontalCuts[i-1])
        for i in range(1,len(verticalCuts)):
            vb.append(verticalCuts[i]-verticalCuts[i-1])
        va.append(h-horizontalCuts[-1])
        vb.append(w-verticalCuts[-1])
        maxh, maxw = max(va), max(vb)
        return  (maxh%M * maxw%M) %M