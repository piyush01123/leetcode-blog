class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size(), repeated=-1, absent=-1;
        unordered_set<int> s;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
                if(s.count(grid[i][j])) repeated = grid[i][j]; else s.insert(grid[i][j]);
        for(int x=1; x<=n*n; x++) if(!s.count(x)) absent = x;
        return {repeated,absent};
    }
};