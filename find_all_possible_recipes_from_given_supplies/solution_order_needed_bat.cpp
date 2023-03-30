class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> G;
        unordered_map<string,int> inDegrees;
        for (int i=0; i<recipes.size(); i++)
        {
            string rec = recipes[i];
            vector<string> itemList = ingredients[i];
            int n = itemList.size();
            if(inDegrees.find(rec)==inDegrees.end()) inDegrees[rec] = n;
            else inDegrees[rec] += n;
            for (string item: itemList)
            {
                if (G.find(item)==G.end()) G[item] = {rec};
                else G[item].push_back(rec);
            }
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
        unordered_set<string> L_set(L.begin(),L.end());
        vector<string> res;
        for (string item: recipes) if (L_set.find(item)!=L_set.end()) res.push_back(item);
        return res;
    }
};