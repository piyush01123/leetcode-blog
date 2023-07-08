class UnionFind
{
    vector<int> roots;
    vector<int> ranks;
public: 
    UnionFind(int sz)
    {
        roots = vector<int>(sz);
        ranks = vector<int>(sz);
        for(int i=0; i<sz; i++){roots[i]=i; ranks[i]=1;}
    }
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return;
        if (ranks[rootX]<ranks[rootY]) swap(rootX,rootY);
        roots[rootY] = rootX;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    int numGroups(int sz)
    {
        unordered_set<int> mySet;
        for (int i=0; i<sz; i++) mySet.insert(find(i));
        return mySet.size();
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(isConnected[i][j])
            uf.unionSet(i,j);
        return uf.numGroups(n);
    }
};