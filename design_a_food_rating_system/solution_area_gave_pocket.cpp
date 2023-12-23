#define psi pair<string,int>
struct F
{
    bool operator()(psi a, psi b)
    {
        if (a.second!=b.second) return a.second<b.second;
        string s1=a.first, s2=b.first;
        int n1=s1.length(), n2=s2.length();
        for(int i=0; i<min(n1,n2); i++) if(s1[i]!=s2[i]) return s1[i]>s2[i];
        return n1>n2;
    }
};

class FoodRatings 
{
    unordered_map<string, string> fc; //food to cuisine
    unordered_map<string, int> fr; //food to rating
    unordered_map<string, priority_queue<psi,vector<psi>,F>> cfr; // cuisine to (food,rating) pairs
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
            cfr[cuisine].push({food,rating});
        }        
    }
    
    void changeRating(string food, int newRating) 
    {
        cfr[fc[food]].push({food,newRating});
        fr[food] = newRating;          
    }
    
    string highestRated(string cuisine) 
    {
        psi res = cfr[cuisine].top();
        while(fr[res.first]!=res.second)
        {
            cfr[cuisine].pop();
            res = cfr[cuisine].top();
        }
        return res.first;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */