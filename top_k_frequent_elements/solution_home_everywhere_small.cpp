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
        vector<int> vfreq;
        while(!freq.empty()) {vfreq.push_back(freq.top()); freq.pop();}
        for (int i=vfreq.size()-1; i>=0; i--)
        {
            int f = vfreq[i];
            for (int key: F[f])
            {
                res.push_back(key);
                if (res.size()==k) return res;
            }
        }
        return res;
    }
};