class Solution {
public:
    void rotate_vec(vector<int>&v, int k)
    {
        reverse(v.begin(),v.end());
        //9,8,7,6,5,4,3,2,1
        rotate(v.begin(),v.begin()+k,v.end());
        //8,7,6,5,4,3,2,1,9
        reverse(v.begin(),v.end());
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        k = k%(m*n);
        vector<int> keys(m*n,0);
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)keys[n*i+j]=grid[i][j];
        rotate_vec(keys,k);
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)grid[i][j]=keys[n*i+j];
        return grid;
    }
};