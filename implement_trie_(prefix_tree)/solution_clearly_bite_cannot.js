class TrieNode {
    constructor()
    {
        this.isEnd = false;
        this.children = new Array(26).fill(null);
    }
}

function getPosition(ch)
{
    return ch.charCodeAt()-'a'.charCodeAt();
}

var Trie = function() {
    this.root = new TrieNode();    
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    cur = this.root;
    for (let i=0; i<word.length; i++)
    {
        idx = getPosition(word.charAt(i));
        if (cur.children[idx]==null)
            cur.children[idx] = new TrieNode();
        cur = cur.children[idx];
    }
    cur.isEnd = true;    
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    cur = this.root;
    for (let i=0; i<word.length; i++)
    {
        idx = getPosition(word.charAt(i));
        if (cur.children[idx]==null) return false;
        cur = cur.children[idx];
    }
    return cur.isEnd;    
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    cur = this.root;
    for (let i=0; i<prefix.length; i++)
    {
        idx = getPosition(prefix.charAt(i));
        if (cur.children[idx]==null) return false;
        cur = cur.children[idx];
    }
    return true;    
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */