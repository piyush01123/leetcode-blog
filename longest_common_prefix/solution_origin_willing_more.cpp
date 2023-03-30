class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size()==1) return strs[0];
        int i=0;
        bool ok=true;
        while (1)
        {
            for (int j=1; j<strs.size(); j++)
            {
                string s=strs[j];
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