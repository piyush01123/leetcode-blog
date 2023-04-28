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

// // Test Case
// int main() {
//     // for displaying booleans as literal strings, instead of 0 and 1
//     cout << boolalpha;
//     UnionFind uf(10);
//     // 1-2-5-6-7 3-8-9 4
//     uf.unionSet(1, 2);
//     uf.unionSet(2, 5);
//     uf.unionSet(5, 6);
//     uf.unionSet(6, 7);
//     uf.unionSet(3, 8);
//     uf.unionSet(8, 9);
//     cout << uf.connected(1, 5) << endl;  // true
//     cout << uf.connected(5, 7) << endl;  // true
//     cout << uf.connected(4, 9) << endl;  // false
//     // 1-2-5-6-7 3-8-9-4
//     uf.unionSet(9, 4);
//     cout << uf.connected(4, 9) << endl;  // true

//     return 0;
// }


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
        int n = strs.size(), res=0;
        // vector<vector<int>> G(n);
        // for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(isSimilar(strs[i],strs[j]))
        // {
        //     G[i].push_back(j);
        //     G[j].push_back(i);
        // }
        // vector<bool>visited(n,false);
        // for (int i=0; i<n; i++) if(!visited[i]) 
        // {
        //     bfs(G,visited,i, -1);
        //     res++;
        // }
        // return res;
        UnionFind uf = UnionFind(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) 
        if(isSimilar(strs[i],strs[j])) uf.unionSet(i, j);
        vector<int> groups(n,-1);
        for(int i=0; i<n; i++) groups[i] = uf.find(i);
        return unordered_set<int>(groups.begin(),groups.end()).size();
    }
};