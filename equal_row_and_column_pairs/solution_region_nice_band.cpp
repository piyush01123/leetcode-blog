class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n=grid.size(), ctr=0;
        map<vector<int>,int> H;
        for(int i=0;i<n;i++) H[grid[i]]++;
        for(int i=0;i<n;i++)
        {
            vector<int> col(n,-1);
            for(int j=0;j<n;j++) col[j]=grid[j][i];
            if (H.count(col)) ctr+= H[col];
        }
        return ctr;
    }
};