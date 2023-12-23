class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        vector<int> res;
        for(int mass: asteroids)
        {
            bool toAdd = true;
            while(mass<0 && !res.empty() && res.back()>0)
            {
                if(abs(mass)>res.back()) res.pop_back();
                else if(abs(mass)==res.back())
                {
                    res.pop_back();
                    toAdd = false;
                    break;
                }
                else if(abs(mass)<res.back())
                {
                    toAdd = false;
                    break;
                }
            }
            if (toAdd) res.push_back(mass);
        }
        return res;
    }
};