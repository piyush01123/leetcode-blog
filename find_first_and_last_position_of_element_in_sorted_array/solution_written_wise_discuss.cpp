class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return vector<int>(2,-1);
        int lo=0, hi=n-1, a=-1, b=-1,mid;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(nums[mid]>target) hi=mid-1;
            else if (nums[mid]<target) lo=mid+1;
            else {a=mid; hi=mid-1;}
        }
        if (nums[mid]==target) a=mid;
        lo=0; hi=n-1;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(nums[mid]>target) hi=mid-1;
            else if (nums[mid]<target) lo=mid+1;
            else {b=mid; lo=mid+1;}
        }
        if (nums[mid]==target) b=mid;
        return vector<int>{a,b};
    }
};