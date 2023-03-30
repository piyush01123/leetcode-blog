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
        vector<pair<string,int>> vec;
        for (auto p: H) vec.push_back({p.first,p.second});
        sort(vec.begin(),vec.end(),comp);
        vector<string>res;
        for (int i=0; i<k; ++i) res.push_back(vec[i].first);
        return res;
    }
};