class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> myset;
    int bot = 1;
    SmallestInfiniteSet() {}
    
    int popSmallest() 
    {
        if (pq.empty()) return bot++;
        int res = pq.top();
        pq.pop();
        myset.erase(res);
        return res;
    }
    
    void addBack(int num) 
    {
        if (!(num<bot && !myset.count(num))) return;
        pq.push(num);
        myset.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */