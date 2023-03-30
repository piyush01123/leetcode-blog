class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>> data;
        for (auto b: buildings) 
        {
            int s=b[0], e=b[1], h=b[2];
            data.push_back({s, -h});
            data.push_back({e, +h});
        }
        sort(data.begin(),data.end());
        multiset<int> pq;
        int prev = 0;
        pq.insert(0);
        vector<vector<int>> res;
        for (auto point: data)
        {
            if (point.second<0) pq.insert(-point.second);
            else pq.erase(pq.find(point.second));
            int cur = *pq.rbegin();
            if (cur!=prev) 
            {
                res.push_back({point.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};