class Solution {
public:
    string makeSmallestPalindrome(string s) 
    {
        int n = s.length();
        for (int i=0; i<n/2; i++)
        {
            char c1=s[i], c2=s[n-1-i];
            if (c1==c2) continue;
            s[i] = s[n-1-i] = min(c1,c2);
        }
        return s;
    }
};