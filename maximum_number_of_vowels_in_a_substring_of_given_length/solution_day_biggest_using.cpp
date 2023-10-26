class Solution {
public:
    int maxVowels(string s, int k) 
    {
        unordered_set<char> vowels {'a','e','i','o','u'};
        int ctr=0;
        for (int i=0; i<k; i++) if (vowels.count(s[i])) ctr++;
        int res=ctr;
        for (int i=k; i<s.length(); i++)
        {
            char inc=s[i], out=s[i-k];
            if (vowels.count(inc))ctr++;
            if (vowels.count(out))ctr--;
            res = max(res,ctr);
        }
        return res;
    }
};