class UnionFind {
public:
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (x==root[x]) return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            root[rootY] = rootX;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
};


class Solution {
public:
    void dfs(vector<vector<int>>&G, vector<bool>&visited, int cur, int par)
    {
        visited[cur] = true;
        for (int nbd: G[cur])
        {
            if (nbd==par) continue;
            if (!visited[nbd]) dfs(G, visited, nbd, cur);
        }
    }
    void bfs(vector<vector<int>>&G, vector<bool>&visited, int cur, int par)
    {
        queue<int>Q;
        Q.push(cur);
        visited[cur] = true;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (int nbd: G[node]) if(!visited[nbd])
            {
                Q.push(nbd);
                visited[nbd] = true;
            }
        }
    }
    bool isSimilar(string s1, string s2)
    {
        int diff=0;
        for (int i=0; i<s1.length(); i++) if (s1[i]!=s2[i]) diff++;
        return (diff==0 || diff==2);
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        UnionFind uf = UnionFind(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) 
        if(isSimilar(strs[i],strs[j])) uf.unionSet(i, j);
        vector<int> groups(n,-1);
        for(int i=0; i<n; i++) groups[i] = uf.find(i);
        return unordered_set<int>(groups.begin(),groups.end()).size();
    }
};