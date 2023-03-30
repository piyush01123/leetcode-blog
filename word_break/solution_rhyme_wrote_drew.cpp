class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> words;
        for (string w: wordDict) words.insert(w);
        int n = s.length();
        vector<bool> valid(n+1, false);
        valid[0] = true;
        for (int j=1; j<=n; j++)
        {
            for (int i=0; i<j; i++)
            {
                if (valid[i] && words.count(string(s.begin()+i, s.begin()+j)))
                {
                    valid[j] = true;
                    break;
                }
            }
        }
        return valid[n];
    }
};