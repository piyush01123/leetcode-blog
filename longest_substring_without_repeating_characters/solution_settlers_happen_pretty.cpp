class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int>H;
        int res=0, j=0;
        for (int i=0; i<s.length(); i++)
        {
            if (H.count(s[i]))
                j = max(j, H[s[i]]+1);
            H[s[i]]=i;
            res = max(res,i-j+1);
        }
        return res;
    }
};