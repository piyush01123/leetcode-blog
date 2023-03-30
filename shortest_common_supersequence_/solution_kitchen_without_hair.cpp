class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length(), n2=str2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for (int i=1; i<=n1; i++)
        {
            for (int j=1; j<=n2; j++)
            {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1];
                if (str1[i-1]==str2[j-1]) c++;
                dp[i][j] = max({a,b,c});
            }
        }
        string res;
        // cout << "LCS" << dp[n1][n2] << n1 << n2 << endl;
        int i=n1, j=n2;
        while (i>0 && j > 0)
        {
            // cout << i << j << dp[i][j] << endl;
            if (dp[i][j]==dp[i-1][j-1])
            {
                // cout << "case1" << endl;
                res += str1[i-1];
                res += str2[j-1];
                --i;--j;
            }
            else
            {
                if (str1[i-1]==str2[j-1])
                {
                    // cout << "case 2.1" << endl;
                    res += str1[i-1];
                    --i; --j;
                }
                else
                {
                    if (dp[i-1][j]==dp[i][j])
                    {
                        // cout << "case 2.2.1" << endl;
                        res += str1[i-1];
                        --i;
                    }
                    else if(dp[i][j-1]==dp[i][j])
                    {
                        // cout << "case 2.2.2" << endl;
                        res += str2[j-1];
                        --j;
                    }
                }
            }
            // cout << res << endl;
        }
        // cout << "IJ" << i << j << endl;
        while(i>0)
        {
            res += str1[i-1];
            --i;
        }
        while(j>0)
        {
            res += str2[j-1];
            --j;
        }
        // cout << res << endl;
        reverse(res.begin(),res.end());
        return res;
    }
};