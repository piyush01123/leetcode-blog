class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n=grid.size(), ctr=0;
        unordered_map<string,int> H;
        for(int i=0;i<n;i++)
        {
            string rowHash = "";
            for(int j=0;j<n;j++) rowHash += to_string(grid[i][j])+",";
            H[rowHash]++;
        }
        for(int i=0;i<n;i++)
        {
            string colHash = "";
            for(int j=0;j<n;j++) colHash += to_string(grid[j][i])+",";
            if (H.count(colHash)) ctr+= H[colHash];
        }
        return ctr;
    }
};