class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int i=0;
        bool ok=true;
        while (1)
        {
            for (string s: strs)
            {
                if (i>=s.length() || s[i]!=strs[0][i])
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