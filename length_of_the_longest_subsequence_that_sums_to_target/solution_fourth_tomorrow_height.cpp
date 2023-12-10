class Solution {
    vector<vector<int>> dp;
public:
    int dfs(vector<int>&nums, int index, int target)
    {
        if (target==0) return 0;
        if (target<0 || index==nums.size()) return -1001;
        if (dp[index][target]!=-1) return dp[index][target];
        int r1 = dfs(nums,index+1,target-nums[index]);
        int r2 = dfs(nums,index+1,target);
        return dp[index][target] = max(1+r1,r2);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) 
    {
        dp.resize(nums.size()+1, vector<int>(target+1,-1));
        int res = dfs(nums,0,target);
        return (res<0) ? -1 : res;
    }
};