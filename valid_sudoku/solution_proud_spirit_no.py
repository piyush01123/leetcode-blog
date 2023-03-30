class Solution:
    def violates(self, items):
        dic = {str(k):0 for k in range(1,10)}
        for item in items:
            if item != '.':
                dic[item]+=1
        return max(list(dic.values()))>1
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            if self.violates(row):
                return False
        flattened = [item for row in board for item in row]
        cols = [flattened[i::9] for i in range(9)]
        for col in cols:
            if self.violates(col):
                return False
        for box_idx in range(9):
            box_row, box_col = box_idx//3, box_idx%3
            box = [row[3*box_col:3*(box_col+1)] for row in \
                   board[3*box_row:3*(box_row+1)]]
            box = [item for row in box for item in row]
            if self.violates(box):
                return False
        return True
        
        