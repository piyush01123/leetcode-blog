class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) 
    {
        if (grid[0][0]!=0) return false;
        int n = grid.size();
        set<vector<int>> moves {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        map<int, vector<int>> H;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) H[grid[i][j]] = vector<int>{i,j};
        for (int i=0; i<(n*n-1); i++)
        {
            int dy = H[i+1][1]-H[i][1], dx = H[i+1][0]-H[i][0];
            vector<int> diff = vector<int>{dx,dy};
            if (!moves.count(diff)) return false;
        }
        return true;
    }
};