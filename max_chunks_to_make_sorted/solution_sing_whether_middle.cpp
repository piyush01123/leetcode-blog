class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n=arr.size(), curMax=INT_MIN, ctr=0;
        for (int i=0; i<n; i++)
        {
            curMax = max(curMax, arr[i]);
            if (curMax == i)
                ctr++;
        }
        return ctr;            
    }
};