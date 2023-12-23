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
                if (len==1) dp[i][j] = true;
                else if (len==2) dp[i][j] = (s[i]==s[j]);
                else dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]) ;
                if (dp[i][j]) res = s.substr(i,len);
            }
        }
        return res;
    }
};