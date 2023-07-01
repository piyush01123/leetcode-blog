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
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<int> board(n,-1);
        vector<vector<int>> boards;
        solve(n,0,board,boards);
        // for(auto row: boards){for(int k:row)cout<<k<<','; cout<<endl;}
        vector<vector<string>> res;
        for(auto config: boards)
        {
            vector<string> chessB(n, string(n,'.'));
            for(int i=0; i<n; i++) chessB[i][config[i]] = 'Q';
            res.push_back(chessB);
        }
        return res;
    }
};

/*
-1,-1,-1,-1
0,-1,-1,-1 -> 0,0,-1,-1
*/
