struct Trie {
    Trie* ch[26] = {};
    bool end = false;
    void insert(string &s, int p = 0) {
        if (p < s.size()) {
            int idx = s[p] - 'a';
            if (ch[idx] == nullptr)
                ch[idx] = new Trie();
            ch[idx]->insert(s, p + 1);
        }
        else
            end = true;
    }
    bool find(string &s, int p = 0, bool skipped = false) {
        if (p == s.size())
            return skipped && end;
        int idx = s[p] - 'a';
        return(ch[idx] != nullptr ? ch[idx]->find(s, p + 1, skipped) : false) || (skipped ? false : find(s, p + 1, true));
    }
};
class Solution{
    public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        Trie t;
        for (auto &w : startWords) {
            sort(begin(w), end(w));
            t.insert(w);
        }
        int res = 0;
        for (auto &w : targetWords) {
            sort(begin(w), end(w));
            res += t.find(w);
        }
        return res;    
    }
};