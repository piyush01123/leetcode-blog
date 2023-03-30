class TimeMap 
{
    unordered_map<string, map<int,string>> data;
    public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        if (!data.count(key))
        {
            data[key] = {{timestamp, value}};
            return;
        }
        if (data[key].count(timestamp)) data[key].erase(timestamp);
        data[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        if (!data.count(key)) return "";
        auto it = data[key].lower_bound(timestamp);
        if (it != data[key].end() && (*it).first==timestamp) 
            return (*it).second;
        if (it == data[key].begin()) return "";
        --it;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */