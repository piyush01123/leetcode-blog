class Solution {
public:
    bool validate(vector<int>board, int row, int col, int sz)
    {
        for (int i=0; i<sz; i++)
        {
            if (i==row) continue;
            int j = board[i];
            if (j==-1) continue;
            if (j==col) return false;
            if ((j-col)==(row-i)) return false;
            if ((j-col)==(i-row)) return false;
        }
        return true;
    }
    void solve(int n, int row, vector<int>&board, vector<vector<int>>&boards)
    {
        if (row==n) boards.push_back(board);
        for (int col=0; col<n; col++)
        {
            if (validate(board,row,col,n))
            {
                board[row] = col;
                solve(n, row+1, board, boards);
                board[row] = -1;
            }
        }
        return;
    }
    int totalNQueens(int n)
    {
        vector<int> board(n,-1);
        vector<vector<int>> boards;
        solve(n,0,board,boards);
        return boards.size();
    }
};