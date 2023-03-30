class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        H = defaultdict(list)
        n = len(arr)
        for i,num in enumerate(arr):
            H[num].append(i)
        res = [None for _ in range(n)]
        for indices in H.values():
            m = len(indices)
            cumSum = [0]
            for i in range(m-1):
                cumSum.append(cumSum[i]+indices[i])
            S = sum(indices)
            for i in range(m):
                res[indices[i]] = S-2*cumSum[i]+(2*i-m)*indices[i]
        return res