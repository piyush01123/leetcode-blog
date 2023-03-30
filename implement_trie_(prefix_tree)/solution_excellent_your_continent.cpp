class Trie {
public:
    vector<Trie*> children = vector<Trie*>(26, nullptr);
    bool isEnd = false;
    Trie() {}
    void insert(string word, int pos=0) 
    {
        if (pos==word.length())
        {
            isEnd = true;
            return;
        }
        int idx = word[pos]-'a';
        if (!children[idx]) children[idx] = new Trie;
        children[idx]->insert(word, pos+1);
    }
    bool search(string word, int pos=0) 
    {
        if (pos==word.length()) return isEnd;
        int idx = word[pos]-'a';
        if (!children[idx]) return false;
        return children[idx]->search(word, pos+1);
    }
    
    bool startsWith(string prefix, int pos=0) 
    {
        if (pos==prefix.length()) return true;
        int idx = prefix[pos]-'a';
        if (!children[idx]) return false;
        return children[idx]->startsWith(prefix, pos+1);        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */