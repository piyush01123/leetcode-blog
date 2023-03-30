class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size(), ctr = 1;

        vector<int> leftMax(n,0), rightMin(n,0);
        rightMin[n-1] = arr[n-1];
        leftMax[0] = arr[0];
        for (int i=n-2; i>=0; i--)
            rightMin[i] = min(rightMin[i+1], arr[i]);
        for (int i=1; i<n; i++)
            leftMax[i] = max(leftMax[i-1], arr[i]);
        
        for (int i=0; i<n-1; i++)
            if (leftMax[i]<=rightMin[i+1])
                ctr++;
        return ctr;
    }
};