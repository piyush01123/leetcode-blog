class Solution {
    unordered_map<int,int> memo;
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if (target==0) return 1;
        if (target<0) return 0;
        int cur=0;
        for (int i=0; i<nums.size(); i++)
            if (memo.count(target-nums[i])) cur += memo[target-nums[i]];
            else
                cur += combinationSum4(nums, target-nums[i]);
        return memo[target] = cur;
    }
};