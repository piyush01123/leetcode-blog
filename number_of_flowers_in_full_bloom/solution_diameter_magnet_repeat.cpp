class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        unordered_map<int,int> changes;
        for (int i=0;i<flowers.size();i++)
        {
            changes[flowers[i][0]]++;
            changes[flowers[i][1]+1]--;
        }
        vector<int> days;
        for(auto [k,v]: changes) days.push_back(k);
        sort(days.begin(),days.end());
        unordered_map<int,int> H;
        int cur=0;
        for (int day: days)
        {
            cur += changes[day];
            H[day] = cur;
        }
        // for (auto [k,v]: H)cout<<k<<':'<<v<<", ";cout<<endl;
        vector<int> res;
        for (int p: people)
        {
            int idx = lower_bound(days.begin(),days.end(),p)-days.begin();
            if (idx==days.size()) idx--;
            if (days[idx]>p) idx--;
            if (idx<0) res.push_back(0);
            else res.push_back(H[days[idx]]);
        }
        return res;
    }
};