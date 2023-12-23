class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.length(), ones=0, zeros=0, res=-1;
        for(int i=0; i<n; i++) if(s[i]-'0') ones++;
        for(int i=0; i<n-1; i++)
        {
            if(s[i]=='0') zeros++; else ones--;
            res = max(res, zeros+ones);
        }
        return res;
    }
};