class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words;
        for (string w: wordDict) words.insert(w);
        int n=s.length();
        
        vector<bool>valid(n+1,false);
        valid[0] = true;
        
        for (int j=1; j<=n; j++)
        {
            bool curr = false;
            for (int i=0; i<j; i++)
            {
                string sub(s.begin()+i, s.begin()+j);
                if (valid[i] && words.count(sub)){curr=true; break;}
            }
            valid[j] = curr;
        }
        return valid[n];
    }
};