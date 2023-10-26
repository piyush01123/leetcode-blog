class UnionFind
{
public:
    unordered_map<string, string> roots;
    unordered_map<string, int> ranks;
    unordered_map<string, double> rates;
    UnionFind(unordered_set<string> &nodes)
    {
        for (string node: nodes)
        {
            roots[node] = node;
            ranks[node] = 1;
            rates[node] = 1;
        }
    }
    void unionSet(string x, string y, double rate)
    {
        auto pairX = find(x), pairY = find(y);
        string rootX = pairX.first, rootY = pairY.first;
        double rateX = pairX.second, rateY = pairY.second;
        if (rootX==rootY) return;
        if (ranks[rootX]==ranks[rootY]) ranks[rootX]++;
        if (ranks[rootX] <ranks[rootY])
        {
            swap(rootX, rootY);
            swap(rateX, rateY);
            rate = 1/rate;
        }
        roots[rootY] = rootX;
        //x=r1Rx, y=r2Ry, x=ry, r1Rx=r(r2Ry), Ry=(r1/(rr2))Rx
        rates[rootY] =  rateX / rateY / rate;
    }
    pair<string,double> find(string x)
    {
        if (x==roots[x]) return {x, rates[x]};
        auto pair = find(roots[x]);
        roots[x] = pair.first;
        rates[x] *= pair.second;
        return {roots[x], rates[x]};
    }
    double conversionFactor(string x, string y)
    {
        auto pairX = find(x), pairY = find(y);
        string rootX = pairX.first, rootY = pairY.first;
        double rateX = pairX.second, rateY = pairY.second;
        if (rootX!=rootY) return -1;
        return rateX/rateY;
    }
};

class Solution {
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
            uf.unionSet(a, b, v);
        }
        for (auto &p: uf.roots) cout<<p.first<<':'<<p.second<<','; cout<<endl;
        vector<double> res;
        for (auto &query: queries)
        {
            string c = query[0], d=query[1];
            if (!nodes.count(c) || !nodes.count(d)) res.push_back(-1);
            else res.push_back(uf.conversionFactor(c, d));
        }
        return res;
    }
};