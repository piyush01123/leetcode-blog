class RandomizedSet {
    unordered_set<int> numset;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (numset.count(val)) return false;
        numset.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (!numset.count(val)) return false;
        numset.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % numset.size();
        auto it = numset.begin();
        for (int i=0; i<idx; ++i) ++it;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */