class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> G;
        for (int i=0; i<recipes.size(); i++)
        {
            for (string item: ingredients[i])
            {
                if (G.find(item)==G.end()) G[item] = {recipes[i]};
                else G[item].push_back(recipes[i]);
            }
        }
        unordered_map<string,int> inDegrees;
        for (string item: supplies) inDegrees[item]=0;
        for (auto item: G)
        {
            for (string item: item.second) if(inDegrees.find(item)==inDegrees.end()) inDegrees[item]=1;
                                           else inDegrees[item]++;
        }
        vector<string> S = supplies;
        vector<string> L;
        while (!S.empty())
        {
            string n = S.back(); // elements in S have no inDegree
            S.pop_back();
            L.push_back(n);
            if (G.find(n)==G.end()) continue;
            vector<string> nodes = G[n];
            for (string m: nodes)
            {
                inDegrees[m]--;
                if (inDegrees[m]==0) S.push_back(m);
            }
        }
        // L is the topological sort
        sort(recipes.begin(),recipes.end());
        sort(L.begin(),L.end());
        vector<string> res = vector<string>(L.size()+recipes.size());
        vector<string>::iterator it = set_intersection(recipes.begin(),recipes.end(),L.begin(),L.end(),res.begin());
        res.resize(it-res.begin());
        return res;
    }
};