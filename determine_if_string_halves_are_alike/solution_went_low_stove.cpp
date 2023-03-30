class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        unordered_set<char>vowels{'a','e','i','o','u','A','E','I','O','U'};
        int n=s.length(),ctr=0;
        for (int i=0; i<n/2; i++) if (vowels.count(s[i])) ctr++;
        for (int i=n/2; i<n; i++) if (vowels.count(s[i])) ctr--;
        return ctr==0;
    }
};