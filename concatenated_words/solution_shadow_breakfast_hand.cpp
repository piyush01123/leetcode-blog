class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(),words.end());
        vector<string> res;
        for (string word: words)
        {
            wordSet.erase(word);
            int n = word.length();
            vector<bool> valid(n+1, false);
            valid[0] = true;
            for (int j=1; j<=n; j++)
                for (int i=0; i<j && !valid[j]; i++)
                    valid[j] = valid[i] && wordSet.count(word.substr(i,j-i));
            if (valid[n]) res.push_back(word);
            wordSet.insert(word);
        }
        return res;        
    }
};