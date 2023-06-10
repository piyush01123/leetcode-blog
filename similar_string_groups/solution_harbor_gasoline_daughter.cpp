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
    bool isSimilar(string s1, string s2)
    {
        int diff=0;
        for (int i=0; i<s1.length(); i++) if (s1[i]!=s2[i]) diff++;
        return (diff==0 || diff==2);
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size(), res=0;
        vector<vector<int>> G(n);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(isSimilar(strs[i],strs[j]))
        {
            G[i].push_back(j);
            G[j].push_back(i);
        }
        vector<bool>visited(n,false);
        for (int i=0; i<n; i++) if(!visited[i]) 
        {
            dfs(G,visited,i, -1);
            res++;
        }
        return res;
    }
};