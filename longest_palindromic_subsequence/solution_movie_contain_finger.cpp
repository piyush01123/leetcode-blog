class Solution {
public:
    int helper(string &s, vector<vector<int>>&dp, int i, int j)
    {
        if (dp[i][j]!=-1) return dp[i][j];
        if (i>j) return 0;
        if (i==j) return 1;
        if (s[i]==s[j]) return dp[i][j] = 2+helper(s,dp,i+1,j-1);
        return dp[i][j] = max(helper(s,dp,i+1,j), helper(s,dp,i,j-1));
    }
    int longestPalindromeSubseq(string s) 
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(s, dp, 0, s.length()-1);
    }
};