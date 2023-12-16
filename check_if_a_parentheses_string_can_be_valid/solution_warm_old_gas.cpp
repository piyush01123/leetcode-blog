class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int cur = 0, n=s.length();
        if (n%2) return false;
        for(int i=0; i<n; i++)
        {
            if (s[i]=='(' || locked[i]=='0') cur++;
            else cur--;
            if(cur<0) return false;
        }
        cur = 0;
        for(int i=n-1; i>=0; i--)
        {
            if (s[i]==')' || locked[i]=='0') cur++;
            else cur--;
            if(cur<0) return false;
        }
        return true;
    }
};