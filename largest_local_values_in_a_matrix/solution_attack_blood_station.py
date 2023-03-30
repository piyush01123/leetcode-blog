class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        res = [[None for _ in range(n-2)] for _ in range(n-2)]
        for i in range(n-2):
            for j in range(n-2):
                # print(i,j,[row[j:j+3] for row in grid[i:i+3]])
                res[i][j] = max([max(row[j:j+3]) for row in grid[i:i+3]])
        return res