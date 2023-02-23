# Solution using Edit Distance Algorithm
```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp (n1+1, vector<int>(n2+1,0));
        for (int i=1; i<=n1; i++) dp[i][0]=i;
        for (int j=1; j<=n2; j++) dp[0][j]=j;
        for (int i=1; i<=n1; i++)
        {
            for (int j=1; j<=n2; j++)
            {
                int a = dp[i-1][j]+1;
                int b = dp[i][j-1]+1;
                int c = dp[i-1][j-1];
                if (word1[i-1]!=word2[j-1]) c+=2;
                dp[i][j]=min({a,b,c});
            }
        }
        return dp[n1][n2];
    }
};
```

The only change we made from edit distance algorithm is that we replaced `c++` to `c+=2` inside the `if` condition. This is because now we are not allowed to do substitution but rather we should be deleting on both sides. Everything else is exactly the same.
Reference:https://leetcode.com/problems/edit-distance/

# Solution using LCS algorithm
## DP using recursion with memoization
```
class Solution {
public:
    int getLCS(string word1, string word2, int n1, int n2, int i, int j, 
               vector<vector<int>>&L)
    {
        if (L[i][j]<0)
        {
            if (i==n1 || j==n2) L[i][j]=0;
            else if (word1[i]==word2[j]) 
                L[i][j] = 1 + getLCS(word1,word2,n1,n2,i+1,j+1,L);
            else L[i][j] = max(getLCS(word1,word2,n1,n2,i+1,j,L), 
                               getLCS(word1,word2,n1,n2,i,j+1,L)
                              );
        }
        return L[i][j];
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> L(n1+1, vector<int>(n2+1,-1));
        int lcs = getLCS(word1, word2, n1, n2, 0, 0, L);
        return n1+n2-2*lcs;
    }
};
```
## DP using iteration
```
class Solution {
public:
    int getLCS(string word1, string word2, int n1, int n2)
    {
        vector<vector<int>> L(n1+1, vector<int>(n2+1,-1));
        for (int i=n1; i>=0; i--)
        {
            for (int j=n2; j>=0; j--)
            {
                if (i==n1 || j==n2) L[i][j]=0;
                else if (word1[i]==word2[j]) L[i][j] = 1+L[i+1][j+1];
                else L[i][j] = max(L[i+1][j], L[i][j+1]);
            }
        }
        return L[0][0];
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        int lcs = getLCS(word1, word2, n1, n2);
        return n1+n2-2*lcs;
    }
};
```