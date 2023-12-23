class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int> wordDict; for (string word: words) wordDict[word]++;
        int strLen=s.length(), numWords = words.size(), lenWords = words[0].length();
        vector<int> res;
        for (int i=0; i<=strLen-numWords*lenWords; i++)
        {
            unordered_map<string,int> curDict;
            for(int j=0; j<numWords; j++) curDict[s.substr(i+j*lenWords, lenWords)]++;
            if (wordDict==curDict) res.push_back(i);
        }
        return res;
    }
};