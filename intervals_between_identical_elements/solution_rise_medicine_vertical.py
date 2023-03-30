class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        H = defaultdict(list)
        n = len(arr)
        for i,num in enumerate(arr):
            H[num].append(i)
        res = [None for _ in range(n)]
        for indices in H.values():
            m = len(indices)
            S = sum([indices[i]-indices[0] for i in range(1,m)])
            res[indices[0]] = S
            for i in range(1,m):
                d = indices[i]-indices[i-1]
                S = S-d*(m-2*i)
                res[indices[i]] = S
        return res
