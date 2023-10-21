class Solution {
    int[][] dp;
    int helper(int[] nums1, int[] nums2, int i, int j)
    {
        if (i==nums1.length || j==nums2.length) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        if (nums1[i]==nums2[j]) return dp[i][j] = 1+helper(nums1,nums2,i+1,j+1);
        else return dp[i][j] = Math.max(helper(nums1,nums2,i+1,j), helper(nums1,nums2,i,j+1));
    }
    public int maxUncrossedLines(int[] nums1, int[] nums2) 
    {
        dp = new int[nums1.length][nums2.length];
        for (int[] row: dp) Arrays.fill(row,-1);
        return helper(nums1, nums2, 0, 0);
    }
}