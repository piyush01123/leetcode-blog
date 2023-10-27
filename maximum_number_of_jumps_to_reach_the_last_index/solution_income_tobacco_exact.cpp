class Solution {
   vector<int> memo = vector<int>(10001,-2);
public:
    int maximumJumps(vector<int>& nums, int target, int cur=0) 
    {
        if (cur==nums.size()-1) return 0;
        if (memo[cur]!=-2) return memo[cur];
        int res = -1;
        for (int i=cur+1; i<nums.size(); i++) if (abs(nums[i]-nums[cur])<=target)
        {
            int res_i = maximumJumps(nums, target, i);
            if (res_i!=-1) res = max(res, 1+res_i);
        }            
        return memo[cur] = res;
    }
};