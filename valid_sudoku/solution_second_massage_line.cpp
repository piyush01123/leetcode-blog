class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<vector<bool>> validRows(9, vector<bool>(9, false)); 
       vector<vector<bool>> validCols(9, vector<bool>(9, false)); 
       vector<vector<bool>> validBoxes(9, vector<bool>(9, false));
       for (int row=0; row<9; row++){
           for (int col=0; col<9; col++){
               if (board[row][col]!='.'){
                   int n = board[row][col]-'1';                   
                   if (validRows[row][n]) return false;
                   if (validCols[col][n]) return false;
                   int box_idx = 3*(row/3)+col/3;
                   if (validBoxes[box_idx][n]) return false;

                   validRows[row][n] = true;
                   validCols[col][n] = true;
                   validBoxes[box_idx][n] = true;                   
               }
           }
       }
    return true;
    }
};