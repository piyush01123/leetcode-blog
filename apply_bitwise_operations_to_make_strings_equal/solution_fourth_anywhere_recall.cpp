class Solution {
public:
    bool makeStringsEqual(string s, string t) 
    {
        if (s==t) return true;
        if (s==string(s.length(),'0')||t==string(t.length(),'0'))
            return false;
        return true;
    }
};