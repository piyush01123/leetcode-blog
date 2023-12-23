#define psi pair<int,string>
class FoodRatings 
{
    unordered_map<string, string> fc; //food to cuisine
    unordered_map<string, int> fr; //food to rating
    unordered_map<string, set<psi>> crf; // cuisine to (-rating,food)
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n = foods.size();
        for(int i=0; i<n; i++)
        {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            fc[food] = cuisine;
            fr[food] = rating;
            crf[cuisine].insert({-rating,food});
        }        
    }
    
    void changeRating(string food, int newRating) 
    {
        string cuisine = fc[food];
        int oldRating = fr[food];
        auto it = crf[cuisine].find({-oldRating,food});
        crf[cuisine].erase(it);
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