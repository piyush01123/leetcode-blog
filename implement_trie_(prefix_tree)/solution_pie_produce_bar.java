class TrieNode {
    public TrieNode[] children;
    public boolean isEnd;
    public TrieNode()
    {
        children = new TrieNode[26];
        isEnd = false;
    }
}

class Trie {
    private TrieNode root;
    public Trie() 
    {
        root = new TrieNode();
    }
    
    public void insert(String word) 
    {
        TrieNode cur = root;
        for (int i=0; i<word.length(); i++)
        {
            char ch = word.charAt(i);
            int idx = ch-'a';
            if (cur.children[idx]==null) 
                cur.children[idx] = new TrieNode();
            cur = cur.children[idx];
        }
        cur.isEnd = true;
    }
    
    public boolean search(String word) 
    {
        TrieNode cur = root;
        for (int i=0; i<word.length(); i++)
        {
            char ch = word.charAt(i);
            int idx = ch-'a';
            if (cur.children[idx]==null) 
                return false;
            cur = cur.children[idx];
        }
        return cur.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for (int i=0; i<prefix.length(); i++)
        {
            char ch = prefix.charAt(i);
            int idx = ch-'a';
            if (cur.children[idx]==null) 
                return false;
            cur = cur.children[idx];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */