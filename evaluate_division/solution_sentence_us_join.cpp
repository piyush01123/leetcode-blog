class UnionFind
{
    unordered_map<string, string> roots;
    unordered_map<string, int> ranks;
    unordered_map<string, double> convRates;
public:
    UnionFind(unordered_set<string>nodes)
    {
        for(string node: nodes)
        {
            roots[node] = node;
            ranks[node] = 1;
            convRates[node] = 1;
        }
        // cout<<roots.size()<<ranks.size()<<convRates.size()<<endl;
    }
    void unionSet(string x, string y, double rate)
    {
        // cout<<x<<y<<rate<<endl;
        auto pairX = find(x), pairY = find(y);
        string rootX = pairX.first, rootY = pairY.first;
        double rateX = pairX.second, rateY = pairY.second;
        if (rootX==rootY) return;
        if (ranks[rootX] < ranks[rootY])
        {
            roots[rootX] = rootY;
            convRates[rootX] = rateY / rateX * rate;
        }
        else if(ranks[rootY] < ranks[rootX])
        {
            roots[rootY] = rootX;
            convRates[rootY] = rateX / rateY / rate ;
        }
        else
        {
            roots[rootY] = rootX;
            ranks[rootX] ++;
            convRates[rootY] = rateX / rateY / rate;
        }
        // cout<<"INPUT:"<<"X:"<<x<<"Y:"<<y<<endl;
        // for (auto &p: convRates) cout<<p.first<<':'<<p.second<<','; cout<<endl;
        // cout<<"FINDONE"<<endl;
        return;
    }
    pair<string,double> find(string x)
    {
        // cout<<"FIND:"<<x<<endl;
        if (x==roots[x]) return {x, convRates[x]};
        auto pair = find(roots[x]);
        roots[x] = pair.first;
        double m = pair.second;
        convRates[x] *= m;
        return {roots[x], convRates[x]};
    }
    double conversionRate(string x, string y)
    {
        // cout<<"CR"<<x<<y<<endl;
        auto pairX = find(x), pairY = find(y);
        string rootX = pairX.first, rootY = pairY.first;
        double rateX = pairX.second, rateY = pairY.second;        
        if (rootX!=rootY) return -1;
        return convRates[x]/convRates[y];
    }
};

class Solution 
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, \
                                vector<vector<string>>& queries) 
    {
        unordered_set<string> nodes;
        for (auto &eqn: equations){nodes.insert(eqn[0]); nodes.insert(eqn[1]);}
        UnionFind uf = UnionFind(nodes);
        for (int i=0; i<equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            uf.unionSet(a,b,v);
        }
        vector<double> res;
        for (auto &query: queries)
        {
            string c=query[0], d=query[1];
            if (!nodes.count(c) || !nodes.count(d)) res.push_back(-1);
            else res.push_back(uf.conversionRate(c,d));
        }
        return res;
    }
};