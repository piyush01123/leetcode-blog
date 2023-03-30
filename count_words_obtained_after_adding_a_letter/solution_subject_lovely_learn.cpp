class Trie
{
    // vector<Trie *> children = vector<Trie *>(26, NULL);
    Trie* children[26] = {};
    bool isEnd = false;
    public:
    void insert(string word, int pos=0)
    {
        if (pos==word.size()){isEnd=true; return;}
        int idx=word[pos]-'a';
        if (children[idx]==NULL) children[idx] = new Trie;
        children[idx]->insert(word, pos+1);
    }
    bool find(string word, int pos=0, bool skipped=false)
    {
        if (pos==word.size()) return isEnd&&skipped;
        int idx = word[pos]-'a';
        // return (children[idx]&&children[idx]->find(word, pos+1, skipped)) || ((!skipped) && find(word, pos+1, true));
        return(children[idx] != nullptr ? children[idx]->find(word, pos + 1, skipped) : false) || (skipped ? false : find(word, pos + 1, true));
    }
};
class Solution {
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