class Trie
{
    Trie* children[2] = {nullptr};
public:
    Trie(){}
    void insert(int n)
    {
        Trie *cur = this;
        for (int i=31; i>=0; i--)
        {
            int bit = (n>>i)&1;
            if (cur->children[bit]==nullptr) cur->children[bit] = new Trie();
            cur = cur->children[bit];
        }
    }
    int maxXor(int n)
    {
        Trie *cur = this;
        int res = 0;
        for (int i=31; i>=0; i--)
        {
            int bit = (n>>i)&1;
            int xbit = 1-bit;
            if (cur->children[xbit]!=nullptr)
            {
                res |= (1<<i);
                cur = cur->children[xbit];
            }
            else
            {
                // children[bit] is not nullptr in this situation
                cur = cur->children[bit];
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int res = -1;
        Trie *trie = new Trie();
        for (int num: nums) trie->insert(num);
        for(int num: nums) res = max(res, trie->maxXor(num));
        return res;
    }
};