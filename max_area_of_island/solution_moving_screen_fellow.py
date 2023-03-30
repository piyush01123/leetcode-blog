class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        seen = set()
        def util(r,c):
            if r<0 or r>=m or c<0 or c>=n or (r,c) in seen or grid[r][c]==0:
                return 0
            seen.add((r,c))
            return 1+util(r+1,c)+util(r-1,c)+util(r,c+1)+util(r,c-1)
        return max([max([util(r,c) for c in range(n)]) for r in range(m)])