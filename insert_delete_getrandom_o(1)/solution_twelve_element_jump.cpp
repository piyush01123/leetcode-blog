class RandomizedSet {
    vector<int> vals;
    unordered_map<int,int> H;
public:
    RandomizedSet(){}
    
    bool insert(int val) 
    {
        if (H.count(val)) return false;
        H[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if (!H.count(val)) return false;
        int idx = H[val];
        vals[idx] = vals.back();
        vals.pop_back();
        H[vals[idx]] = idx;
        H.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        int idx = rand() % vals.size();
        return vals[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */