class FoodRatings 
{
    unordered_map<string, string> fc; //food to cuisine
    unordered_map<string, int> fr; //food to rating
    unordered_map<string, set<pair<int,string>>> crf; // cuisine to (-rating,food)
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        for(int i=0; i<foods.size(); i++)
        {
            string food = foods[i], cuisine = cuisines[i]; int rating = ratings[i];
            fc[food] = cuisine; fr[food] = rating;
            crf[cuisine].insert({-rating,food});
        }        
    }
    
    void changeRating(string food, int newRating) 
    {
        string cuisine = fc[food];
        crf[cuisine].erase(crf[cuisine].find({-fr[food],food}));
        crf[cuisine].insert({-newRating,food});
        fr[food] = newRating;          
    }
    
    string highestRated(string cuisine) 
    {
        return crf[cuisine].begin()->second;        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */