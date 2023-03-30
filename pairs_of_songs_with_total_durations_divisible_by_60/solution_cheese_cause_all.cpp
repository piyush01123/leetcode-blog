class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        unordered_map<int,int> comps;
        for (int t: time)
        {
            int mod=t%60;
            if (comps.find(mod)!=comps.end()) res+=comps[mod];
            int comp = (60-mod)%60;
            if (comps.find(comp)==comps.end()) comps[comp]=1;
            else comps[comp]++;            
        }
        return res;
    }
};