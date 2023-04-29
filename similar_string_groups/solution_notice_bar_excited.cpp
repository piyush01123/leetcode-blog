class UnionFind {
public:
    UnionFind(int sz) : root(sz), ranks(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            ranks[i] = 1;
        }
    }
    int find(int x) {
        if (x==root[x]) return x;
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if(ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        else if (ranks[rootX]<ranks[rootY]) swap(rootY,rootX);
        root[rootY] = rootX;
    }
private:
    vector<int> root;
    vector<int> ranks;
};

class Solution {
public:
    bool isSimilar(string s1, string s2)
    {
        int diff=0;
        for (int i=0; i<s1.length(); i++) if (s1[i]!=s2[i]) if(++diff>2) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        UnionFind uf = UnionFind(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) 
        if(isSimilar(strs[i],strs[j])) uf.unionSet(i, j);
        unordered_set<int> myset;
        for(int i=0; i<n; i++) myset.insert(uf.find(i));
        return myset.size();
    }
};