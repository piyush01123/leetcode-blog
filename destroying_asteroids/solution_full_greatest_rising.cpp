class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        sort(asteroids.begin(),asteroids.end());
        for (int a: asteroids)
        {
            if(mass<a) return false;
            if(mass>=asteroids.back()) return true;
            mass += a;
        }
        return true;
    }
};