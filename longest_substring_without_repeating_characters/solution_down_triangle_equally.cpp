class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.length(), i=0, j=0, res=0;
        unordered_set<char> chars;
        while (i<n && j<n)
        {
            if (chars.count(s[j]))
            {
                chars.erase(s[i]);
                i++;
            }
            else
            {
                chars.insert(s[j]);
                res = max(res,j-i+1);
                j++;
            }
        }
        return res;
    }
};