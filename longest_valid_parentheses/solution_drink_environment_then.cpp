class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.length(), res=0;
        if (n==0) return  0;
        vector<int> dp(n,0); // dp[i] = Len(longest valid substring ending at i) 
        for (int i=1; i<n; i++)
        {
            if (s[i]=='(') continue;
            if (s[i-1]=='(') dp[i] = 2 + (i>=2 ? dp[i-2] : 0); //() case
            else 
            {
                // "))" case
                if (i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                    dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};