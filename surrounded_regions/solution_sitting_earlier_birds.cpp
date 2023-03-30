class Solution {
public:
    void dfs(vector<vector<char>> &board, int m, int n, int i, int j, vector<pair<int,int>>&isle)
    {
        if (i<0||i>=m||j<0||j>=n||board[i][j]!='O') return;
        board[i][j] = '*';
        isle.push_back({i,j});
        dfs(board,m,n,i-1,j,isle);
        dfs(board,m,n,i+1,j,isle);
        dfs(board,m,n,i,j-1,isle);
        dfs(board,m,n,i,j+1,isle);
    }
    void surround(vector<vector<char>> &board, int m, int n,vector<pair<int,int>>&isle)
    {
        bool toSurround = true;
        for (auto p: isle)
            if (p.first==0 || p.first==(m-1) || p.second==0 || p.second==n-1)
            {
                toSurround = false;
                break;
            }
        if (toSurround)
        {
            for (auto p: isle)
                board[p.first][p.second] = 'X';            
        }
        else
        {
            for (auto p: isle)
                board[p.first][p.second] = 'O';            
        }
        
    }
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n=board[0].size();
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (board[i][j]=='O')
                {
                    vector<pair<int,int>> isle;
                    dfs(board,m,n,i,j,isle);
                    surround(board,m,n,isle);
                }
            }
        }
    }
};