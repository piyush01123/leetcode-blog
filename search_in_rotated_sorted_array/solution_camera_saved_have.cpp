class Solution {
public:
    int countRotations(vector<int>& nums) 
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
        return mid;
    }

    int search(vector<int>& nums, int target) 
    {
        int pivot = countRotations(nums);
        vector<int>::iterator it;
        if (target < nums[0] || pivot==0)
            it = lower_bound(nums.begin()+pivot, nums.end(), target);
        else
            it = lower_bound(nums.begin(), nums.begin()+pivot, target);
        if (it==nums.end()) return -1;
        if (*it==target) return it-nums.begin();
        return -1;
    }
};