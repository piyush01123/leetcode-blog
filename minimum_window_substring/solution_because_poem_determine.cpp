class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> map(128,0);
        for (char ch: t) map[ch]++;

        int start=0, end=0, ctr=t.length(), minStart=0, minLen=INT_MAX;
        while (end<s.length())
        {
            if (map[s[end++]]-- > 0) ctr--;
            while (ctr==0)
            {
                if (end-start < minLen)
                {
                    minLen = end-start;
                    minStart = start;
                }
                if (map[s[start++]]++==0) ctr++;
            }
        }
        return (minLen==INT_MAX) ? "" : s.substr(minStart,minLen);
    }
};