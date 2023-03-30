class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        minDiff = 1e10
        for i in range(1,n):
            diff = arr[i]-arr[i-1]
            if diff<minDiff:
                minDiff = diff
        res = []
        for i in range(1,n):
            diff = arr[i]-arr[i-1]
            if diff==minDiff:
                res.append([arr[i-1],arr[i]])
        return res