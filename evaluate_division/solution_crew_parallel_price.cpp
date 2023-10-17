class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string,double>>>&G, unordered_set<string>&visited, \
                string source, string target, double factor)
    {
        if (source==target) return factor;
        for (auto &nbd: G[source]) if (!visited.count(nbd.first))
        {
            visited.insert(nbd.first);
            double res = dfs(G,visited,nbd.first,target,factor*nbd.second);
            if (res!=-1) return res;
        }
        return -1;
    }
    double solveQuery(unordered_map<string, vector<pair<string,double>>> &G, string c, string d)
    {
        unordered_set<string> visited;
        visited.insert(c);
        return dfs(G, visited, c, d, 1);
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n = equations.size();
        unordered_map<string, vector<pair<string,double>>> G;
        for (int i=0; i<n; i++)
        {
            string a=equations[i][0], b=equations[i][1];
            double v=values[i];
            G[a].push_back({b, v});
            G[b].push_back({a, 1/v});
        }
        vector<double> res(queries.size());
        for (int i=0; i<queries.size(); i++)
        {
            string c = queries[i][0], d=queries[i][1];
            if (!G.count(c) || !G.count(d)) res[i]=-1;
            else res[i] = solveQuery(G, queries[i][0], queries[i][1]);
        }            
        return res;
    }
};