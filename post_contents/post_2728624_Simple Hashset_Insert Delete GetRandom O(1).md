```
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
```