class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda k: k[1], reverse=True)
        curr, res = 0,0
        for boxid, boxType in enumerate(boxTypes):
            n, w = boxType
            if curr+n >= truckSize:
                res += w*(truckSize-curr)
                break
            curr += n
            res += n*w
        return res
            