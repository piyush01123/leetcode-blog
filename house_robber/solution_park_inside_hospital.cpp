class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> money(nums.size(),0);
        int a=nums[0], b=max(nums[0],nums[1]), c;
        for (int i=2; i<nums.size(); i++)
        {
            c=b;
            b=max(a+nums[i],b);
            a=c;
        }
        return b;
    }
};