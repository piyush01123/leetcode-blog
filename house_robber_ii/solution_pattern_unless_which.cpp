class Solution {
public:
    int houseRobber(vector<int> nums)
    {
        if(nums.size()==1)return nums[0];
        vector<int> money(nums.size(),0);
        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);
        for (int i=2; i<nums.size(); i++) 
            money[i] = max(money[i-2]+nums[i], money[i-1]);
        return money[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int a = houseRobber(vector<int>(nums.begin(),nums.end()-1));
        int b = houseRobber(vector<int>(nums.begin()+1,nums.end()));
        return max(a,b);
    }
};