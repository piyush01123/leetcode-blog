class Solution {
public:
    int countHomogenous(string s) 
    {
        int res=0, ctr=0, mod=1e9+7;
        for (int i=0; i<s.length(); i++)
        {
            if (i==0 || s[i]!=s[i-1]) ctr=1; else ctr++;
            res += ctr;
            res %= mod;
        }
        return res;
    }
};