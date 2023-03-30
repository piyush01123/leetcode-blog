class LRUCache 
{
    list<pair<int,int>> data;
    unordered_map<int, list<pair<int,int>>::iterator> H;
    int cap;
public:
    LRUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if (!H.count(key)) return -1;
        data.splice(data.begin(), data, H[key]); // bring to front
        return H[key]->second;
    }
    
    void put(int key, int value) 
    {
        if (H.count(key))
        {
            // key already present in cache, so just update
            data.splice(data.begin(), data, H[key]);
            H[key]->second = value;
            return;
        }
        if (data.size()==cap)
        {
            int least_recent = data.back().first;
            data.pop_back();
            H.erase(least_recent);
        }
        data.push_front({key, value});
        H[key] = data.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */