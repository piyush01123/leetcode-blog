class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        // dp[i] = Answer for s[:i]
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = (s[0]>'0')?1:0;
        for (int i=2; i<=n; i++)
        {
            int a = (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')) ? dp[i-2] : 0;
            int b = (s[i-1]>'0') ? dp[i-1] : 0;
            dp[i] = a + b;
        }
        return dp[n];
    }
};