class Solution {
public:
    int houseRobber(vector<int> nums, int lo, int hi)
    {
        if(lo==hi)return nums[lo];
        int a = nums[lo], b= max(nums[lo], nums[lo+1]), b_old;
        for (int i=lo+2; i<=hi; i++) 
        {
            b_old=b;
            b = max(a+nums[i],b);
            a = b_old;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int a = houseRobber(nums, 0, n-2);
        int b = houseRobber(nums, 1, n-1);
        return max(a,b);
    }
};