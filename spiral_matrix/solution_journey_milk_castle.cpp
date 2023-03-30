void pv(vector<int>v){for(int k:v)cout<<k<<',';cout<<endl;}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size(), i=0, j=0;
        int sy=0, sx=0, ey=m, ex=n; // m=ey=3, n=ex=4
        vector<int> res;
        while (res.size() < m*n)
        {
            // cout << sx << sy << ex << ey << endl;
            while (res.size() < m*n && j<ex)
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            j--; i++; ex--;
            // pv(res);
            while (res.size() < m*n && i<ey)
            {
                res.push_back(matrix[i][j]);
                i++;
            }
            i--; j--; ey--;
            // pv(res);
            while (res.size() < m*n && j>=sx)
            {
                res.push_back(matrix[i][j]);
                j--;
            }
            j++; i--; sx++;
            // pv(res);
            while (res.size() < m*n && i>sy)
            {
                res.push_back(matrix[i][j]);
                i--; 
            }
            i++; j++; sy++;
            // pv(res);
        }
        return res;
    }
};

/*
 1   2   3   4   5   6
 7   8   9  10  11  12
13  14  15  16  17  18
19  20  21  22  23  24
25  26  27  28  29  30
*/