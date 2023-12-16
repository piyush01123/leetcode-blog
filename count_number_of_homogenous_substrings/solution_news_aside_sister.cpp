class Solution {
public:
    int countHomogenous(string s) 
    {
        int res=1, ctr=1, mod=1e9+7;
        for (int i=1; i<s.length(); i++)
        {
            if (s[i]==s[i-1]) ctr++; else ctr=1;
            res += ctr;
            res %= mod;
        }
        return res;
    }
};