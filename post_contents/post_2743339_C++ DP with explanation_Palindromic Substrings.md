Maintain a boolean 2D matrix table to store palindome-ity. Specifically `dp[i][j]` denotes `s[i,..,j]` is a palindrome or not (i and j included). 
The tricky part is that you have to traverse from Length = 1 to Length = n. For each length explore all possible starting positions for `i` and j then becomes `i+len-1`
The recurrence relation for palindrome-ity is
```
dp[i][j] =  (s[i]==s[j] && dp[i+1][j-1])
```
Basically it says if the outer two characters are same and the inside string is a palindrome then as a whole is a palindrome.
However, there is no inner string for strings of length 1 and 2. Hence we have to modify:
```
dp[i][j] =  (s[i]==s[j] && (len<=2 || dp[i+1][j-1]))
```

C++ code:
```
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
```