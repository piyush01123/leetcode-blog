class Solution {
public:
    vector<int> merge(vector<int>&left, vector<int>&right)
    {
        int n1=left.size(), n2=right.size();
        vector<int> merged(n1+n2);
        int i=0, j=0, k=0;
        while(i<n1 && j<n2)
        {
            if(left[i]<right[j]) merged[k++] = left[i++];
            else merged[k++] = right[j++];
        }
        while (i<n1) merged[k++] = left[i++];
        while (j<n2) merged[k++] = right[j++];
        return merged;
    }
    vector<int> mergeSort(vector<int>&nums, int n)
    {
        if (n==1) return nums;
        vector<int> left(nums.begin(), nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2, nums.end());
        left = mergeSort(left, n/2);
        right = mergeSort(right, n-n/2);
        vector<int> merged = merge(left, right);
        return merged;
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        return mergeSort(nums, nums.size());
    }
};