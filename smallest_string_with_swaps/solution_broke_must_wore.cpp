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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n = s.length();
        UnionFind uf = UnionFind(n);
        for (auto &p: pairs)
        {
            int u=p[0], v=p[1];
            if (v<u) swap(u,v);
            uf.unionSet(u,v);
        }
        unordered_map<int,vector<int>> H;
        for (int i=0; i<n; i++) H[uf.find(i)].push_back(i);
        for (auto &[root, nodes]: H)
        {
            vector<char> chars;
            for (int node: nodes) chars.push_back(s[node]);
            sort(chars.begin(),chars.end());
            sort(nodes.begin(),nodes.end());
            for(int i=0; i<nodes.size(); i++) s[nodes[i]] = chars[i];
        }
        return s;
    }
};