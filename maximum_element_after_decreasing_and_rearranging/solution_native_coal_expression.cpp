class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int ctr = 1;
        for (int i=1; i<arr.size(); i++)
            if (arr[i]>=ctr+1) ctr++;
        return ctr;        
    }
};