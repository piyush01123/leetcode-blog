class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> comps(60,0);
        int res=0;
        for (int t: time)
        {
            res += comps[t%60];
            comps[(60-(t%60))%60]++;
        }
        return res;
    }
};