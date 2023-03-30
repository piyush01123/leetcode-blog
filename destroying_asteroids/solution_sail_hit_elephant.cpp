class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for (int asteroid: asteroids)
        {
            if (mass<asteroid) return false;
            if (mass>=asteroids[asteroids.size()-1]) return true;
            mass += asteroid;
        }
        return true;
    }
};