class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n,0));
        for(int i=0; i<m; i++) for(int j=0; j<n; j++)
        {
            int sum = 0, ctr=0;
            for(int ii=max(0,i-1); ii<=min(m-1,i+1); ii++)
                for(int jj=max(0,j-1); jj<=min(n-1,j+1); jj++)
                    {sum += img[ii][jj]; ctr++;}
            res[i][j] = sum/ctr;
        }
        return res;
    }
};