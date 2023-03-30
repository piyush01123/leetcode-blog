
string add_one(string s, int l)
{
    int i=l-1;
    while (i>=0 && s[i]!='0')
    {
        s[i]='0';
        i--;
    }
    if (i>=0) s[i]='1';
    else s="1"+s;
    return s;
}

class Solution {
public:
    int numSteps(string s) {
        int ctr=0;
        while (s!="1")
        {
            int l = s.length();
            if (s[l-1]=='0') s = string (s.begin(), s.end()-1);
            else s = add_one(s, l);
            ctr ++;
        }
        return ctr;
    }
};