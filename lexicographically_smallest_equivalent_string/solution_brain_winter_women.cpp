class Solution {
public:
    void dfs(int u, vector<vector<int>>&G, vector<int>&cover, vector<bool>&visited)
    {
        if (visited[u]) return;
        visited[u] = true;
        cover.push_back(u);
        for (int v: G[u]) dfs(v, G, cover, visited);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        vector<vector<int>> G(26, vector<int>{});
        for (int i=0; i<s1.length(); i++)
        {
            int u = s1[i]-'a', v=s2[i]-'a';
            if (u==v) continue;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        // for (int u=0;u<26;u++){cout<<u<<':';for(int v: G[u])cout<<v<<','; cout<<endl;}
        vector<bool> visited(26, false);
        vector<int> mapping(26);
        for (int i=0; i<26; i++) mapping[i] = i;
        for (int i=0; i<26; i++)
        {
            if (visited[i]) continue;
            vector<int> cover;
            dfs(i, G, cover, visited);
            for (int j: cover) mapping[j] = i;
        }
        for (int i=0; i<baseStr.length(); i++) baseStr[i] = 'a'+mapping[baseStr[i]-'a'];
        return baseStr;
    }
};