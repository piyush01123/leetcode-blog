class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_map<string,int> code;
        int n = 0;
        for (string r: recipes)
            if (!code.count(r))
                code[r] = n++;
        for (auto v: ingredients)
            for (string i: v)
                if (!code.count(i))
                    code[i] = n++;
        for (string s: supplies)
            if (!code.count(s))
                code[s] = n++;
        vector<string> revCode(n);
        for (auto p: code) revCode[p.second] = p.first;
 
        vector<vector<int>> G(n, vector<int>{});
        vector<int> inDegrees(n, 0);
        for (int i=0; i<recipes.size(); i++)
        {
            string recipe = recipes[i];
            auto ingred = ingredients[i];
            for (string item: ingred)
            {
                int u = code[item], v = code[recipe];
                G[u].push_back(v);
                inDegrees[v]++;
            }
        }
            
        queue<int> Q;
        unordered_set<int> doable;
        for (string s: supplies)
            Q.push(code[s]);
        
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            doable.insert(u);
            for (int v: G[u])
            {
                inDegrees[v]--;
                if (inDegrees[v]==0)
                    Q.push(v);
            }
        }
        
        vector<string> res;
        for (string r: recipes)
            if (doable.count(code[r]))
                res.push_back(r);
        return res;
        
    }
};