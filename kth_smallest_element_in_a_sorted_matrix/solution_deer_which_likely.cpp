class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size();
        int lo=matrix[0][0], hi=matrix[n-1][n-1];
        while (lo<hi)
        {
            int mid = lo+(hi-lo)/2, ctr=0;
            for (int i=0; i<n; ++i)
                ctr += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            if (ctr<k) lo = mid+1;
            else hi=mid;
        }
        return lo;
    }
};