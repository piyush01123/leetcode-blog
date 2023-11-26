class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.length();
        vector<vector<int>> dp (n, vector<int>(n, -1));
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                if (len==1) dp[i][j] = 1;
                else if (len==2) dp[i][j] = ((s[i]==s[j]) ? 2 : 1);
                else
                {
                    int a = dp[i+1][j-1] + ((s[i]==s[j])?2:0);
                    int b = dp[i+1][j];
                    int c = dp[i][j-1];
                    dp[i][j] = max(max(a,b),c);
                }
            }
        }
        // for(auto row:dp){for(int k:row)cout<<k<<','; cout<<endl;}
        return dp[0][n-1];
    }
};