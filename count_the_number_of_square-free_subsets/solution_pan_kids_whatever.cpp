class Solution {
public:
    int dp[1001][1024] = {}, mod = 1000000007;
    int f[31] = {-1, 0, 1, 2, -1, 4, 3, 8, -1, -1, 5, 16, -1, 32, 9, 6,
                -1, 64, -1, 128, -1, 10, 17, 256, -1, -1, 33, -1, -1, 512, 7};
    int dfs(int i, int mask, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (dp[i][mask] != 0) return dp[i][mask];
        int ans = dfs(i + 1, mask, nums) % mod;
        if (f[nums[i]] != -1 && (mask & f[nums[i]]) == 0)
            ans = (ans + 1 + dfs(i + 1, mask + f[nums[i]], nums)) % mod;
        return dp[i][mask] = ans;
    }
    int squareFreeSubsets(vector<int>& nums) {
        return dfs(0, 0, nums);   
    }
};