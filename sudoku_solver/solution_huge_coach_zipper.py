class Solution:
    def is_safe(self, board, row, col, num):
        if board[row][col] != '.':
            return False
        for p_col in range(9):
            if board[row][p_col]==num:
                return False
        for p_row in range(9):
            if board[p_row][col]==num:
                return False
        box_start_row = row - row%3
        box_start_col = col - col%3
        for p_row in range(3):
            for p_col in range(3):
                if board[box_start_row+p_row][box_start_col+p_col]==num:
                    return False
        return True

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        flattened = [item for row in board for item in row]
        if '.' not in flattened:
            return True
        empty = flattened.index('.')
        row, col = empty//9, empty%9
        for num in range(1,10):
            if self.is_safe(board,row,col,str(num)):
                board[row][col] = str(num)
                if self.solveSudoku(board):
                    return True
                board[row][col] = '.'
        return False
