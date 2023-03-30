class Solution {
public:
    bool hasUnfilled(vector<vector<char>>& board, int &i, int &j)
    {
        for (i=0; i<9; i++)
            for (j=0; j<9; j++)
                if (board[i][j]=='.')
                    return true;
        return false;
    }
    bool validate(vector<vector<char>>& board, int i, int j, char ch)
    {
        for (int jj=0; jj<9; jj++) if (board[i][jj]==ch) return false;
        for (int ii=0; ii<9; ii++) if (board[ii][j]==ch) return false;
        for (int ii=0; ii<9; ii++)
            for (int jj=0; jj<9; jj++)
                if (ii/3==i/3 && jj/3==j/3 && board[ii][jj]==ch)
                    return false;
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int i, j;
        if (!hasUnfilled(board, i, j)) return true;
        for (int val=0; val<9; val++)
            if (validate(board,i,j,'1'+val))
            {
                board[i][j] = '1' + val;
                if (solve(board)) return true;
                board[i][j] = '.';
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};