class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size(), res=1, a, b, c, d;
        vector<pair<int,int>> dp(n);
        dp[0] = {1,1};
        for (int i=1; i<n; i++)
        {
            int a = (nums1[i]>=nums1[i-1]) ? dp[i-1].first+1 : 1;
            int b = (nums1[i]>=nums2[i-1]) ? dp[i-1].second+1 : 1;
            int c = (nums2[i]>=nums1[i-1]) ? dp[i-1].first+1 : 1;
            int d = (nums2[i]>=nums2[i-1]) ? dp[i-1].second+1 : 1;
            dp[i] = {max(a,b), max(c,d)};
            res = max({res, dp[i].first, dp[i].second});
        }
        return res;
    }
};