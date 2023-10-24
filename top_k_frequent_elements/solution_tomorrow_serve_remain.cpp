class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        unordered_map<int,int> H;
        for(int num: nums) H[num]++;
        unordered_map<int,vector<int>> F; set<int,greater<int>> freq;
        for(auto &p: H) {F[p.second].push_back(p.first); freq.insert(p.second);}
        for(int f: freq)
        {
            for (int key: F[f])
            {
                res.push_back(key);
                if (res.size()==k) return res;
            }
        }
        return res;
    }
};