class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size(), lo=0, hi=n-1, mid;
        while (lo<=hi)
        {
            mid = lo + (hi-lo)/2;
            int prev = (mid-1+n)%n, next = (mid+1)%n;
            if (nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                break;
            else if (nums[mid] <= nums[hi])
                hi = mid-1;
            else
                lo = mid+1; // nums[mid]>=nums[0]
        }
        return nums[mid];
    }
};