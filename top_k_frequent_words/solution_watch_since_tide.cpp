bool comp(pair<string,int>a, pair<string,int>b)
{
    if (a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> H;
        for (string w: words) H[w]++;
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)*> pq(comp);
        for (auto p: H)
        {
            pq.push({p.first,p.second});
            if (pq.size()>k) pq.pop();
        }
        vector<string>res;
        while (!pq.empty())
        {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        return res;
    }
};