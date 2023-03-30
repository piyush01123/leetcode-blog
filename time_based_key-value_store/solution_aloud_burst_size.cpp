bool cmp(pair<int,string>a, pair<int,string>b)
{
    return a.first < b.first;
}

class TimeMap {
    unordered_map<string, vector<pair<int,string>>> data;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        data[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) 
    {
        if (!data.count(key)) return "";
        // auto vec = data[key];
        // pair<int,string> p{timestamp,""};
        // auto it = lower_bound(vec.begin(), vec.end(), p, cmp);
        // if (it != vec.end() && (*it).first==timestamp) 
        //     return (*it).second;
        // if (it == vec.begin()) return "";
        // --it;
        // return (*it).second;
        int lo=0, hi=data[key].size();
        while (lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            if (data[key][mid].first <= timestamp)
                lo = mid+1;
            else
                hi = mid;
        }
        if (hi==0) return "";
        return data[key][hi-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */