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