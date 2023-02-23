First solve LCS https://leetcode.com/problems/longest-common-subsequence/
Then use the DP table and backtrack to construct the answer in reverse.
- Start at bottom right
- Case 1: If same as upper left corner of current cell, then `LCS(i,j)=LCS(i-1,j-1)`, hence just copy both the characters. Order will not matter.
- Case 2.1: If not find out whether the current character is common in both the strings. Hence `LCS(i,j)=LCS(i-1,j-1)+1`. So copy this character but only once.
- Case 2.2: This is the case when `LCS(i,j)` has come from either `LCS(i-1,j)` (Case 2.2.1) or `LCS(i,j-1)` (Case 2.2.2). Find out which one it is and copy that character and advance the pointer (Only of the two pointers will be advanced).
- When you reach `i=0` or `j=0`, then just copy the remaining characters.

```
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
        // cout << "LCS" << dp[n1][n2] << endl;
        int i=n1, j=n2;
        while (i>0 && j > 0)
        {
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
        }
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
        reverse(res.begin(),res.end());
        return res;
    }
};
```
Another variation of this problem can to find the LCS substring. To solve this, only case 2.2.1 will count.