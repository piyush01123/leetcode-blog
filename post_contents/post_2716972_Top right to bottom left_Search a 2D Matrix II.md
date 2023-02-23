The idea is to start from top right cell. If it is larger than target than we can ignore last column, if smaller we can ignore first row. This way we keep moving.
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int i=0, j=n-1;
        while (i<m && j>=0)
        {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else  i++;
        }
        return false;
    }
};
```