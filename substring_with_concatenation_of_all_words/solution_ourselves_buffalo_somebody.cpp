class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int> wordDict;
        for (string word: words) wordDict[word]++;
        int strLen=s.length(), numWords = words.size(), lenWords = words[0].length();
        vector<int> res;
        for (int i=0; i<=strLen-numWords*lenWords; i++)
        {
            string sub = s.substr(i, numWords*lenWords);
            unordered_map<string,int> curDict;
            bool valid=true;
            for (int j=0; j<numWords; j++)
            {
                string cur = sub.substr(j*lenWords, lenWords);
                if (!wordDict.count(cur)) {valid=false;break;}
                curDict[cur]++;
                if (curDict[cur]>wordDict[cur]) {valid=false;break;}
            }
            if (valid) res.push_back(i);
        }
        return res;
    }
};