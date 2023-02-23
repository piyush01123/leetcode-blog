Once you ponder over the question, it is easy to find the recurrence relation:
Consider k (# faces of each die) to be constant. Then, 
```
rolls(n,target) = rolls(n-1,target-1) + rolls(n-1, target-2) + rolls(n-1, target-3) + ... + rolls(n-1,target-k)
```

If you don"t understand the above equation, consider that first item in the RHS corresponds to the case when last die has value 1 (and so the remaining n-1 dice must sum to target-1), second item corresponds to last die having value 2 (and so the remaining n-1 dice must sum to target-2) and so on such that last item corresponds to last die having value k (and so the remaining n-1 dice must sum to target-k). 

We will create a DP table bottom up. Size of table will be `(n+1, target+1)`. Top row and leftmost column will be zero except `dp[0][0] = 1`.  `dp[i,j]` denotes `rolls(i,j)`

Example of DP table for `numRollsToTarget(1,6,3)`:

| |T=0|T=1|T=2|T=3|
|--|---|---|---|---|
| N=0 | 1 | 0 | 0 | 0 |
| N=1 | 0 | 1 | 1 | 1 |


Example of DP table for `numRollsToTarget(2,6,7)`:

| |T=0|T=1|T=2|T=3|T=4|T=5|T=6|T=7
|--|---|---|---|---|---|---|---|---|
| N=0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| N=1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
| N=2 | 0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 

This gives us the following code:
```
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // dp[i,j] denotes numRollsToTarget(i,k,j)
        dp[0][0] = 1;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=target; j++)
            {
                int temp = 0;
                for (int p=1; p<=min(k,j); p++) 
                    temp += dp[i-1][j-p];
                dp[i][j] = temp;
            }
        }
        return dp[n][target];
    }
};
```

The above code is completely correct and will work (for small input). However we need to also handle large input and do the modulo thing. Hence here is the modified version.

```
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // dp[i,j] denotes numRollsToTarget(i,k,j)
        dp[0][0] = 1;
        int mod = 1000000007;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=target; j++)
            {
                int temp = 0;
                for (int p=1; p<=min(k,j); p++) 
                {
                    temp = (temp%mod) + ( dp[i-1][j-p]%mod);
                    temp %= mod;
                }
                dp[i][j] = temp;
            }
        }
        return dp[n][target];
    }
};
```