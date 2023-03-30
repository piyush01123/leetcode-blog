class Solution {
public:
    int getNumNeighbors(vector<vector<int>>board,int m,int n, int i, int j)
    {
        int ctr=0;
        if (i>0)
        {
            if (j>0) ctr+=board[i-1][j-1]%2;
            ctr += board[i-1][j]%2;
            if (j<n-1) ctr+=board[i-1][j+1]%2;
        }
        if (j>0) ctr+=board[i][j-1]%2;
        if (j<n-1) ctr+=board[i][j+1]%2;
        if (i<m-1)
        {
            if (j>0) ctr+=board[i+1][j-1]%2;
            ctr += board[i+1][j]%2;
            if (j<n-1) ctr+=board[i+1][j+1]%2;
        }
        return ctr;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int num_neighbors=getNumNeighbors(board,m,n,i,j);
                if (board[i][j]==1 && num_neighbors<2) board[i][j]=1;
                if (board[i][j]==1 && num_neighbors>3) board[i][j]=1;
                if (board[i][j]==0 && num_neighbors==3)board[i][j]=2;
                if (board[i][j]==1 && (num_neighbors==2 || num_neighbors==3))board[i][j]=3;
            }
        }
        for (int i=0;i<m;i++) for (int j=0;j<n;j++) board[i][j]/=2;
    }
};