class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size()%2==1) return false;
        int bal=0, n=s.size();
        for (int i=0; i<n; i++)
        {
            if (s[i]=='(' || locked[i]=='0') bal++;
            else bal--;
            if (bal<0) return false;
        }
        bal = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i]==')' || locked[i]=='0') bal++;
            else bal--;
            if (bal<0) return false;
        }
        return true;
    }
};