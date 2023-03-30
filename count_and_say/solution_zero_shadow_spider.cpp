class Solution {
public:
    string countAndSay(int n) 
    {
        if (n==1) return to_string(n);
        string s = countAndSay(n-1), res="";
        int i=0, len=s.length();
        while(i<len)
        {
            int j = i;
            while(j<len && s[j]==s[i]) j++;
            res.push_back('0'+(j-i));
            res.push_back(s[i]);
            i = j;
        }
        return res;
    }
};