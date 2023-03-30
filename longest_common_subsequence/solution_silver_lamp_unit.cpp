class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1=text1.length(), n2=text2.length();
        vector<vector<int>> dp = vector<vector<int>>(n1+1, vector<int>(n2+1,0));
        for (int i=1; i<=n1; i++)
        {
            for (int j=1; j<=n2; j++)
            {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1];
                if (text1[i-1]==text2[j-1]) c++;
                dp[i][j] = max({a,b,c});
            }
        }
        return dp[n1][n2];
    }
};