class Solution:
    def maximumRows(self, mat: List[List[int]], cols: int) -> int:
        m,n = len(mat), len(mat[0])
        totals = [sum(row) for row in mat]
        res = 0
        for subset in itertools.combinations(range(n),cols):
            score = sum([sum([row[y] for y in subset])==tot for row,tot in zip(mat,totals)])
            res = max(res,score)
        return res