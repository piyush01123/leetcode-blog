class Solution {
public:
    double solveQuery(unordered_map<string, vector<pair<string,double>>> &G, string c, string d)
    {
        queue<pair<string,double>>Q;
        unordered_set<string> visited;
        Q.push({c,1});
        visited.insert(c);
        while(!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                auto pair = Q.front();
                Q.pop();
                string cur=pair.first;
                double val=pair.second;
                if (cur==d) return val;
                for (auto nbd: G[cur]) if (!visited.count(nbd.first))
                {
                    if (nbd.first==d) return val*nbd.second;
                    visited.insert(nbd.first);
                    Q.push({nbd.first, val*nbd.second});
                }
            }
        }
        return -1;
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