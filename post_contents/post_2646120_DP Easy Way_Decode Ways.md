Let `n = length(s)`
Now let `dp` be an array of length `n+1`. Define `dp[i]` as the answer for the string `s[0:i]` that is first `i` characters. Hence `dp[n]` will contain the final answer.

Constructing `dp` array.
- `dp[0] = 1`
- `dp[1] = 1` if `s[0] > "0"`  else `0`.
- `dp[i] = (condition1) ? dp[i-2]  : 0   +   (condition2) ? dp[i-1] : 0`
`condition1` states that the last two characters at` i` form a valid alphabet (b/w [10,26]) and `condtition 2` states that the last character at `i` forms a valid alphabet (b/w [1,9]).

```
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        // dp[i] = Answer for s[:i]
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = (s[0]>"0")?1:0;
        for (int i=2; i<=n; i++)
        {
            int a = (s[i-2]=="1" || (s[i-2]=="2" && s[i-1]<="6")) ? dp[i-2] : 0;
            int b = (s[i-1]>"0") ? dp[i-1] : 0;
            dp[i] = a + b;
        }
        return dp[n];
    }
};
```