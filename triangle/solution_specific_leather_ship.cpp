class Solution {
public:
    void pv(vector<int> v){for(int k:v)cout<<k<<';';cout<<endl;}
    int minimumTotal(vector<vector<int>>& triangle) {
        int nrows=triangle.size(); // 4
        for (int row=1; row<nrows; row++)
        {
            int ncols=row+1; // row=3, ncols=4
            for (int col=1; col<ncols-1; col++) // 4->[1,2], 3->[1]
            {
                int prev = min(triangle[row-1][col-1],triangle[row-1][col]);
                triangle[row][col]+=prev;
            }
            triangle[row][0]+=triangle[row-1][0];
            triangle[row][ncols-1]+=triangle[row-1][ncols-2];
            // pv(triangle[row]);
        }
        vector<int>last_row = triangle[nrows-1];
        return *min_element(last_row.begin(), last_row.end());
    }
};