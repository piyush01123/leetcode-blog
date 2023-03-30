class Solution {
public:
    int getNumNeighbors(vector<vector<int>>board,int m,int n, int i, int j)
    {
        int ctr=0;
        for (int x=max(i-1,0);x<min(i+2,m);x++)
            for (int y=max(j-1,0);y<min(j+2,n);y++) ctr+=board[x][y]&1;
        ctr-=board[i][j]&1;
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
        for (int i=0;i<m;i++) for (int j=0;j<n;j++) board[i][j]>>=1;
    }
};
