class Solution {
public:
    bool find_empty(vector<vector<char>> &board, int &row, int &col){
        for (row=0; row<9; row++)
            for (col=0; col<9; col++)
                if (board[row][col]=='.')
                    return true;
        return false;
    }
    bool is_safe(vector<vector<char>> board, int row, int col, char num){
        for (int p_col=0; p_col<9; p_col++)
            if (board[row][p_col]==num) return false;
        for (int p_row=0; p_row<9; p_row++)
            if (board[p_row][col]==num) return false;
        int bsr = row-row%3, bsc = col-col%3;
        for (int p_row=0; p_row<3; p_row++)
            for (int p_col=0; p_col<3; p_col++)
                if (board[bsr+p_row][bsc+p_col]==num) return false;
        return true;
    }
    bool solve(vector<vector<char>> &board){
        int row, col;
        if (!find_empty(board, row, col)) return true;
        for (int num=0; num<9; num++){
            if (is_safe(board, row, col, '1'+num)){
                board[row][col] = '1'+num;
                if (solve(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
