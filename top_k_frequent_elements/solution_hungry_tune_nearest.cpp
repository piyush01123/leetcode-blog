class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        unordered_map<int,int> H;
        for(int num: nums) H[num]++;
        unordered_map<int,vector<int>> F; 
        priority_queue<int,vector<int>,greater<int>> freq;
        for(auto &p: H) 
        {
            if (!F.count(p.second)) freq.push(p.second);
            if (freq.size()>k) freq.pop();
            F[p.second].push_back(p.first);    
        }
        priority_queue<int> freq2;
        while(!freq.empty()) {freq2.push(freq.top()); freq.pop();}
        while(!freq2.empty())
        {
            int f = freq2.top(); freq2.pop();
            for (int key: F[f])
            {
                res.push_back(key);
                if (res.size()==k) return res;
            }
        }
        return res;
    }
};