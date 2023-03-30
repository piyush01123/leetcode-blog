class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> money(nums.size(),0);
        int a=nums[0], b=max(nums[0],nums[1]), b_old;
        for (int i=2; i<nums.size(); i++)
        {
            b_old=b;
            b=max(a+nums[i],b);
            a=b_old;
        }
        return b;
    }
};