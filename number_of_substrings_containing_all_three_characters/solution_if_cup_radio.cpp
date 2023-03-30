class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length(), res=0, a=-1, b=-1, c=-1;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='a') a = i;
            if (s[i]=='b') b = i;
            if (s[i]=='c') c = i;
            if (a!=-1 && b!=-1 && c!=-1)
            {
                int minIdx = min({a,b,c});
                res += 1+minIdx;
            }
        }
        return res;
    }
};