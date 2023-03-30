class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        int n = s.length();
        vector<bool> valid(n+1, false);
        valid[0] = true;
        for (int j=1; j<=n; j++)
            for (int i=0; i<j && !valid[j]; i++)
                valid[j] = valid[i] && words.count(s.substr(i,j-i));
        return valid[n];
    }
};