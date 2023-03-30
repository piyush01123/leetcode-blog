class Solution {
public:
    vector<int> mapping = vector<int>(26,-1);
    int Find(int u)
    {
        if (mapping[u]==u) return u;
        return mapping[u] = Find(mapping[u]);
    }
    void Union(int u, int v)
    {
        u = Find(u);
        v = Find(v);
        if (u<v) mapping[v] = u;
        if (v<u) mapping[u] = v;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        for (int i=0; i<26; i++) mapping[i] = i;
        for (int i=0; i<s1.length(); i++) Union(s1[i]-'a', s2[i]-'a');
        // for (int i=0; i<26; i++) cout<<i<<':'<<mapping[i]<<','<<Find(i)<<endl;
        for (int i=0; i<baseStr.length(); i++) baseStr[i] = 'a'+Find(baseStr[i]-'a');
        return baseStr;
    }
};