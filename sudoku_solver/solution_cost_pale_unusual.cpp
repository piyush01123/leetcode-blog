class Solution {
public:
    // bool find_empty(vector<vector<char>> &board, int &row, int &col){
    //     for (row=0; row<9; row++)
    //         for (col=0; col<9; col++)
    //             if (board[row][col]=='.')
    //                 return true;
    //     return false;
    // }
    int find_empty(vector<vector<char>> board){
        for (int row=0; row<9; row++)
            for (int col=0; col<9; col++)
                if (board[row][col]=='.')
                    return 9*row+col;
        return -1;
    }
    // bool is_safe_row(vector<vector<char>> board, int row, int col, char num){
    //     for (int p_col=0; p_col<9; p_col++)
    //         if (board[row][p_col]==num) return false;
    //     return true;
    // }
    // bool is_safe_col(vector<vector<char>> board, int row, int col, char num){
    //     for (int p_row=0; p_row<9; p_row++)
    //         if (board[p_row][col]==num) return false;
    //     return true;
    // }
    // bool is_safe_box(vector<vector<char>> board, int row, int col, char num){
    //     int bsr = row-row%3, bsc = col-col%3;
    //     for (int p_row=0; p_row<3; p_row++)
    //         for (int p_col=0; p_col<3; p_col++)
    //             if (board[bsr+p_row][bsc+p_col]==num) return false;
    //     return true;
    // }
    // bool is_safe(vector<vector<char>> board, int row, int col, char num){
    //     if (is_safe_row(board, row, col, num))
    //         if (is_safe_col(board, row, col, num))
    //             if (is_safe_box(board, row, col, num))
    //                 return true;
    //     return false;
    // }
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
        int row_col = find_empty(board);
        if (row_col==-1) return true;
        int row = row_col/9, col = row_col%9;
        // int row, col;
        // if (!find_empty(board, row, col)) return true;
        for (int num=1; num<=9; num++){
            if (is_safe(board, row, col, '0'+num)){
                board[row][col] = '0'+num;
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
