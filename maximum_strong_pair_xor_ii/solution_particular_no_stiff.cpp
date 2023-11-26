class Trie{
    vector<Trie*> children; int count;
public:
    Trie(){children = vector<Trie*>(2,NULL); count=0;}
    void modify(int n, int incr){
        Trie *cur = this;
        for (int i=31; i>=0; i--){
            cur->count += incr;
            int bit = (n>>i)&1;
            if (cur->children[bit]==NULL) cur->children[bit] = new Trie();
            cur = cur->children[bit];
        }
        cur->count += incr;
    }
    int maxXorN(int n){
        int res=0;
        Trie *cur = this;
        for (int i=31; i>=0; i--){
            int bit = (n>>i)&1;
            int xbit = 1-bit;
            if (cur->children[xbit]!=NULL && cur->children[xbit]->count>0){
                res |= (1<<i);
                cur = cur->children[xbit];
            }
            else if (cur->children[bit]!=NULL && cur->children[bit]->count>0)
                cur = cur->children[bit];
        }
        return res;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) 
    {
        int n=nums.size(), j=0, res=0;
        sort(nums.begin(),nums.end());
        Trie *trie = new Trie();
        for (int i=0; i<n; i++)
        {
            // cout<<'i'<<i<<"insert"<<nums[i]<<endl;
            trie->modify(nums[i], 1);
            while(2*nums[j]<nums[i])
            {
                // cout<<'j'<<j<<"delete"<<nums[j];
                trie->modify(nums[j], -1);
                j++;
            }
            // cout<<endl;
            int maxXor = trie->maxXorN(nums[i]);
            // cout << "maxXor" << maxXor << endl;
            res = max(res, maxXor);
        }
        return res;    
    }
};