Just remember to keep track of start and end indices for x and y directions.
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size(), i=0, j=0;
        int sy=0, sx=0, ey=m, ex=n; // m=ey=3, n=ex=4
        vector<int> res;
        while (res.size() < m*n)
        {
            while (res.size() < m*n && j<ex)
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            j--; i++; ex--;
            while (res.size() < m*n && i<ey)
            {
                res.push_back(matrix[i][j]);
                i++;
            }
            i--; j--; ey--;
            while (res.size() < m*n && j>=sx)
            {
                res.push_back(matrix[i][j]);
                j--;
            }
            j++; i--; sx++;
            while (res.size() < m*n && i>sy)
            {
                res.push_back(matrix[i][j]);
                i--; 
            }
            i++; j++; sy++;
        }
        return res;
    }
};
```