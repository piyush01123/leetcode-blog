class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        string res;
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i<=n-len; i++)
            {
                int j = i+len-1;
                dp[i][j] = s[i]==s[j] && ((len<=2) || dp[i+1][j-1]);
                if (dp[i][j]) res = s.substr(i,len);
            }
        }
        return res;
    }
};