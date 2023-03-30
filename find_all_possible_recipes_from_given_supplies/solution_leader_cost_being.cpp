class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> items = unordered_set<string>(supplies.begin(), supplies.end());
        while(true)
        {
            int a = items.size();
            for (int i=0; i<recipes.size(); i++)
            {
                if (items.find(recipes[i])!=items.end()) continue;
                bool all_present=true;
                for (string item: ingredients[i])
                {
                    if (items.find(item)==items.end()){all_present=false;break;}
                }
                if (all_present) items.insert(recipes[i]);
            }
            int b = items.size();
            if (a==b) break;
        }
        vector<string> res;
        for (string item: recipes) if(items.find(item)!=items.end()) res.push_back(item);
        return res;
    }
};