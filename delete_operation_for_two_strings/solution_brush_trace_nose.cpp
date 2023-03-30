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