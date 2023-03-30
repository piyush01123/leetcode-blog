class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        for cb in combinations(range(1,10),k):
            if sum(cb)==n:
                res.append(list(cb))
        return res