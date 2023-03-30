class Solution:
    def numIslands(self, grid: 'List[List[str]]') -> 'int':
        self.n_rows = len(grid)
        if self.n_rows == 0:
            return 0
        self.n_cols = len(grid[0])
        if self.n_cols == 0:
            return 0
        n_islands = 0
        for row in range(self.n_rows):
            for col in range(self.n_cols):
                if grid[row][col] == '1':
                    self.convert_land(grid, row, col)
                    n_islands += 1
        return n_islands
    
    def convert_land(self, grid, row, col):
        if row < 0 or row >= self.n_rows:
            return
        if col < 0 or col >= self.n_cols:
            return
        if grid[row][col] != '1':
            return
        
        grid[row][col] = '2'
        
        options = [(row+1,col),(row-1,col),(row,col+1),(row,col-1)]
        for p_row, p_col in options:
            self.convert_land(grid, p_row, p_col)