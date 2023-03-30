class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>H1,H2;
        for (int i=0; i<s.length(); i++)
        {
            char a=s[i], b=t[i];
            if ((H1.count(a) && H1[a]!=b)||(H2.count(b)&&H2[b]!=a)) return false;
            H1[a] = b;
            H2[b] = a;
        }
        return true;
    }
};