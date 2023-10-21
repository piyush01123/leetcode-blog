class Solution {
    unordered_map<int,int>cache;
public:
    int dfs(int n, vector<vector<int>>&G, vector<int> inDegree, int mask, int k)
    {
        if (mask==0) return 0;
        if (cache.count(mask)) return cache[mask];
        vector<int> doable;
        for(int i=0; i<n; i++) if((mask&(1<<i)) && !inDegree[i]) doable.push_back(i);
        int res = INT_MAX;
        for (auto comb: combinations(doable, k))
        {
            int newMask = mask;
            vector<int> newInDegree = inDegree;
            for (int u: comb)
            {
                newMask ^= (1<<u);
                for(int v: G[u]) newInDegree[v]--;
            }
            res = min(res, 1+dfs(n, G, newInDegree, newMask, k));
        }
        return cache[mask] = res;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) 
    {
        vector<vector<int>> G(n);
        vector<int> inDegree(n,0);
        for(auto r: relations)
        {
            int u=r[0]-1, v=r[1]-1;
            G[u].push_back(v);
            inDegree[v]++;
        }
        return dfs(n, G, inDegree, (1<<n)-1, k);
    }

    vector<vector<int>> combinations(vector<int>v, int k)
    {
        if (v.size()<=k) return {v};
        vector<int> cur;
        vector<vector<int>> res;
        generateCombinations(v, k, cur, 0, res);
        return res;
    }

    void generateCombinations(vector<int>&v, int k, vector<int>&cur, int index, vector<vector<int>>&res)
    {
        if (k==0){res.push_back(cur); return;}
        if (index==v.size()) return;
        cur.push_back(v[index]);
        generateCombinations(v, k-1, cur, index+1, res);
        cur.pop_back();
        generateCombinations(v, k, cur, index+1, res);
    }
};