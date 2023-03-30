class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), maxlen=0;
        vector<vector<bool>> L(n, vector<bool>(n,false));
        string res = "";
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i+len<=n; i++)
            {
                int j = i+len-1;
                if (s[i]==s[j] && (len<=2 || L[i+1][j-1]))
                {
                    L[i][j] = true;
                    if (len>maxlen)
                    {
                        maxlen = len;
                        res = string(s.begin()+i, s.begin()+i+len);
                    }
                }
            }
        }
        return res;
    }
};