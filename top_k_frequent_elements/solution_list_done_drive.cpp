class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        unordered_map<int,int> H;
        for(int num: nums) H[num]++;
        unordered_map<int,vector<int>> F; priority_queue<int> freq;
        for(auto &p: H) 
        {
            if (!F.count(p.second)) freq.push(p.second);
            F[p.second].push_back(p.first);    
        }
        while(freq.size())
        {
            int f = freq.top(); freq.pop();
            for (int key: F[f])
            {
                res.push_back(key);
                if (res.size()==k) return res;
            }
        }
        return res;
    }
};