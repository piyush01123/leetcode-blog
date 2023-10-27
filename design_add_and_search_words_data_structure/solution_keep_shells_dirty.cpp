class Trie
{
    vector<Trie*> children;
    bool isEnd;
public:
    Trie(){children = vector<Trie*>(26,NULL); isEnd=false;}
    void add(string word, int index)
    {
        if (index==word.length()) {isEnd=true; return;}
        int pos = word[index]-'a';
        if (children[pos]==NULL) children[pos] = new Trie();
        children[pos]->add(word, index+1);
    }
    bool search(string word, int index)
    {
        if (index==word.length()) return isEnd;
        if (word[index]=='.')
        {
            for(int i=0; i<26; i++) if(children[i]!=NULL && \
                children[i]->search(word,index+1)) return true;
            return false;
        }
        int pos = word[index]-'a';
        if (children[pos]==NULL) return false;
        return children[pos]->search(word, index+1);
    }
};

class WordDictionary {
    Trie *trie;
public:
    WordDictionary() {trie = new Trie();}    
    void addWord(string word) {trie->add(word,0);}    
    bool search(string word) {return trie->search(word,0);}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */