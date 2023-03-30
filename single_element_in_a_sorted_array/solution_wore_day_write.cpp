class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size(), lo=0, hi=n-1;
        while (lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            if (mid%2==1 && nums[mid]==nums[mid-1]) lo = mid+1;
            else if (mid%2==0 && nums[mid]==nums[mid+1]) lo = mid+1;
            else hi = mid;
        }
        return nums[lo];
    }
};