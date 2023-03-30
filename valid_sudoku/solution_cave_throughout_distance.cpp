#define usc unordered_set<char>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<usc> rows = vector<usc>(9,usc{});
        vector<usc> cols = vector<usc>(9,usc{});
        vector<usc> boxes= vector<usc>(9,usc{});
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                char ch = board[i][j];
                if (ch=='.') continue;
                usc row = rows[i], col = cols[j], box=boxes[3*(i/3)+(j/3)];
                if (row.count(ch) || col.count(ch) || box.count(ch))
                    return false;
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[3*(i/3)+(j/3)].insert(ch);
            }
        }
        return true;
    }
};