class Solution {
public:
    unordered_map<char,int> H;
    int bitmask(string word)
    {
        int m=0;
        for (char ch: word) m^=H[ch];
        return m;
    }
    void create_map()
    {
        for (int i=0; i<26; i++) H['a'+i]=1<<i;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> seen;
        create_map();
        for (string word: startWords) seen.insert(bitmask(word));
        int res=0;
        for (string word: targetWords)
        {
            int m=bitmask(word);
            for (char ch: word)
            {
                if (seen.find(m^H[ch])!=seen.end())
                {
                    res+=1;
                    break;
                }
            }
        }
        return res;
    }
};