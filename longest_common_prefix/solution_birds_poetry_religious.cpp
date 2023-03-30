bool cmp(const string &s, const string &t)
{
    return s.size() < t.size();
}
class Solution {
public:
        string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        int i=0;
        bool ok=true;
        while (i<strs[0].length())
        {
            for (string s: strs)
            {
                if (s[i]!=strs[0][i])
                {
                    ok=false;
                    break;
                }
            }
            if(!ok) break;
            ++i;
        }
        return string(strs[0].begin(),strs[0].begin()+i);
    }
};