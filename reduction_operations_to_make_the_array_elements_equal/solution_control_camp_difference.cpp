class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        unordered_map<int,int>H;
        for(int n: nums) H[n]++;
        vector<int> keys;
        for (auto &[k,v]: H) keys.push_back(k);
        sort(keys.begin(),keys.end());
        int res = 0;
        for (int i=1; i<keys.size(); i++) res += (H[keys[i]]*i);
        return res;
    }
};