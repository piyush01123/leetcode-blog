class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_map<string,vector<string>> G;
        unordered_map<string,int> inDegrees;
        unordered_set<string> makeable;
        vector<string> res;
        
        for (int i=0; i<recipes.size(); i++)
        {
            string recipe = recipes[i];
            for (string item: ingredients[i])
            {
                G[item].push_back(recipe);
                inDegrees[recipe]++;
            }
        }
        
        while (supplies.size()>0)
        {
            string item = supplies.back();
            makeable.insert(item);
            supplies.pop_back();
            for (string nbd: G[item])
            {
                inDegrees[nbd]--;
                if (inDegrees[nbd]==0)
                    supplies.push_back(nbd);
            }
        }
        
        for (string recipe: recipes)
            if (makeable.count(recipe))
                res.push_back(recipe);
        return res;
    }
};