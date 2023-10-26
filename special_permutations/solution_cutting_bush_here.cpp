class Solution {
    vector<vector<int>> dp;
    int mod=1e9+7;
public:
    int helper(vector<int>&nums, int cur, int mask, int n)
    {
        if (dp[cur][mask]!=-1) return dp[cur][mask];
        if (mask+1==(1<<n)) return dp[cur][mask]=1;
        int res=0;
        for(int i=0; i<n; i++)
        {
            // not included till now and condition is met
            if (((mask&(1<<i))==0) &&  ((nums[i]%nums[cur]==0)||(nums[cur]%nums[i]==0)))
            {
                res += helper(nums, i, (mask|(1<<i)), n)  %  mod;
                res %= mod;
            }
        }
        return dp[cur][mask] = res;
    }
    int specialPerm(vector<int>& nums) 
    {
        int n = nums.size(), res=0;
        dp = vector<vector<int>>(n+1, vector<int>((1<<n)+1, -1));
        for (int i=0; i<n; i++)
        {
            res += helper(nums, i, (1<<i), n)  %  mod;
            res %= mod;
        }
        return res;
    }
};
