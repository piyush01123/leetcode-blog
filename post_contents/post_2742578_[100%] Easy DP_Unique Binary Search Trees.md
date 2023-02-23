Assume that you already know `numTrees(1), numTrees(2), numTrees(3),..., numTrees(n-1)` and want to calculate `numTrees(n)`.
We have `n` choices for root. For choice `root` as root let us calculate number of trees. Nodes `1,2,...,root-1` have to be in left subree and nodes `root+1,root+2,...,n` have to be in right subtree. 

**Number of trees with root `root` = (Number of trees that can be formed from nodes `1,2,...,root-1`) * (Number of trees that can be formed from nodes `root+1,root+2,...,n`)`**

Hence
```
numTrees(n) with root = numTrees(root-1)+numTrees(n-root)`
```

C++ Code:
```
class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i=1; i<=n; i++)
        {
            int ctr = 0;
            for (int root=1; root<=i; root++)
                ctr += dp[root-1]*dp[i-root];
            dp[i] = ctr;
        }
        return dp[n];
    }
};
```
```
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
Memory Usage: 6 MB, less than 71.42% of C++ online submissions for Unique Binary Search Trees.
```