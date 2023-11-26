class UnionFind
{
    vector<int> roots;
    vector<int> sizes;
public:
    UnionFind(int sz): roots(sz), sizes(sz)
    {
        for(int i=0; i<sz; i++){roots[i]=i; sizes[i]=1;}
    }
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return;
        if (sizes[rootX]<sizes[rootY]) swap(rootX,rootY);
        sizes[rootX] += sizes[rootY];
        roots[rootY] = rootX;
    }
    int find(int x)
    {
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x]);
    }
    bool isConnected(int x, int y)
    {
        return (find(x)==find(y));
    }
    int numGroups(int n)
    {
        for(int i=0; i<n; i++) cout<<i<<':'<<find(i)<<',';cout<<endl;
        unordered_set<int>mySet;
        for(int i=0; i<n; i++) mySet.insert(find(i));
        return mySet.size();
    }
};



class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> edgesT1, edgesT2, edgesT3;
        for (auto &edge: edges)
        {
            if (edge[0]==1) edgesT1.push_back(edge);
            if (edge[0]==2) edgesT2.push_back(edge);
            if (edge[0]==3) edgesT3.push_back(edge);
        }
        int ctr = 0;
        UnionFind ufAlice=UnionFind(n), ufBob=UnionFind(n);
        for (auto &edge: edgesT3)
        {
            int u=edge[1]-1, v=edge[2]-1;
            if (ufAlice.isConnected(u,v) && ufBob.isConnected(u,v)) ctr++;
            else {ufAlice.unionSet(u,v); ufBob.unionSet(u,v);}
        }
        for (auto &edge: edgesT1)
        {
            int u=edge[1]-1, v=edge[2]-1;
            if (ufAlice.isConnected(u,v)) ctr++;
            else ufAlice.unionSet(u,v); 
        }
        for (auto &edge: edgesT2)
        {
            int u=edge[1]-1, v=edge[2]-1;
            if (ufBob.isConnected(u,v)) ctr++;
            else ufBob.unionSet(u,v); 
        }
        if (ufAlice.numGroups(n)!=1 || ufBob.numGroups(n)!=1) return -1;
        return ctr;
    }
};