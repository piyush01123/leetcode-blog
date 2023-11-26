class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<vector<int>> positions(26);
        int ctr=0;
        for (int i=0; i<s.length(); i++)
            positions[s[i]-'a'].push_back(i);
        for (int i=0; i<26; i++)
        {
            if (positions[i].size()<2) continue;
            int x=positions[i].front(), y=positions[i].back();
            unordered_set<char> between;
            for(int j=x+1; j<y; j++) between.insert(s[j]);
            ctr += between.size();
        }
        return ctr;
    }
};
/*
a - [0,1,4]
b - [2]
c - [3]
j j j j j

*/