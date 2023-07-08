class UnionFind {
public:
    UnionFind(int sz) : root(sz), ranks(sz) {
        for (int i = 0; i < sz; ++i) root[i] = i;
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
    bool isConnected(int x, int y){return (find(x)==find(y));}
private:
    vector<int> root;
    vector<int> ranks;
};



class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        auto cmp = [](const vector<int>&veca, const vector<int>&vecb){return veca[2]<vecb[2];};
        sort(edgeList.begin(), edgeList.end(), cmp);
        for(int i=0; i<queries.size(); i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);

        UnionFind uf = UnionFind(n);
        vector<bool>res(queries.size());
        int edgeIdx = 0;
        for (auto &query: queries)
        {
            int p=query[0], q=query[1], limit=query[2], qIdx=query[3];
            while (edgeIdx<edgeList.size()) 
            {
                int u=edgeList[edgeIdx][0], v=edgeList[edgeIdx][1], dis=edgeList[edgeIdx][2];
                if (dis>=limit) break;
                uf.unionSet(u, v);
                edgeIdx++;
            }
            res[qIdx] = uf.isConnected(p,q);
        }
        return res;
    }
};