class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length(), ctr = 0;
        vector<vector<bool>> dp(n, vector(n,false));
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i<=n-len; i++)
            {
                int j = i+len-1;
                if (s[i]==s[j] && (len<=2 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    ctr++;
                }
            }
        }
        return ctr;
    }
};