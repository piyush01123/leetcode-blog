class Solution {
public:
    bool dfs(vector<vector<char>>& board, int m, int n, int i,  int j, string word, int index)
    {
        if (i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[index]) return false;
        board[i][j] = '*';
        if (index==word.length()-1) return true;
        bool res =  dfs(board,m,n,i-1,j,word,index+1) ||
                       dfs(board,m,n,i+1,j,word,index+1) ||
                       dfs(board,m,n,i,j-1,word,index+1) ||
                       dfs(board,m,n,i,j+1,word,index+1);
        board[i][j] = word[index];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (dfs(board, m, n, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};